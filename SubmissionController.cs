// --------------------------------------------------------------------------------------------------------------------
// <copyright file="SubmissionController.cs" company="Florida Department of Education">
//   Copyright (c) State of Florida 2014
// </copyright>
// --------------------------------------------------------------------------------------------------------------------

namespace DOE.OELPFP.WebUI.Controllers
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Web.Mvc;
    using System.Web.Script.Serialization;

    using DOE.OELPFP.BusinessServices;
    using DOE.OELPFP.BusinessServices.BusinessObjects;
    using DOE.OELPFP.BusinessServices.ServiceLayer;
    using DOE.OELPFP.Common.Utilities;
    using DOE.OELPFP.Common.Serialization;
    using DOE.OELPFP.DataTransferObjects;
    using DOE.OELPFP.WebUI.Infrastructure.Attributes;
    using DOE.OELPFP.WebUI.Models;
    using DOE.OELPFP.WebUI.Infrastructure;
    using Newtonsoft.Json;

    /// <summary>
    /// SubmissionController Class.
    /// </summary>
    [Authorize]
    public class SubmissionController : BaseController
    {
        /// <summary>
        /// The provider service
        /// </summary>
        private readonly IProviderService _providerService;

        /// <summary>
        /// The provider application service
        /// </summary>
        private readonly IProviderApplicationService _providerApplicationService;

        /// <summary>
        /// The provider application service
        /// </summary>
        private readonly IProcessControlService _processControlService;

        /// <summary>
        /// The form data service
        /// </summary>
        private readonly IFormDataService _formDataService;

        /// <summary>
        /// The classroomInstructor service
        /// </summary>
        private readonly IClassroomInstructorService _classroomInstructorService;

        /// <summary>
        /// The provider profile extra service
        /// </summary>
        private readonly IProviderProfileExtraService _providerProfileExtraService;

        /// <summary>
        /// The comment service
        /// </summary>
        private readonly ICommentService _commentService;
        private IProviderService _providerService1;
        private IProviderApplicationService _providerApplicationService1;
        private IProcessControlService _processControlService1;
        private IFormDataService _formDataService1;
        private IClassroomInstructorService _classroomInstructorService1;
        private IProviderSelectionService _providerSelectionService;

        /// <summary>
        /// Initializes a new instance of the <see cref="SubmissionController" /> class.
        /// </summary>
        /// <param name="providerService">The provider service.</param>
        /// <param name="providerApplicationService">The provider application service.</param>
        /// <param name="processControlService">The process control service.</param>
        /// <param name="formDataService">The form data service.</param>
        /// <param name="classroomInstructorService">The classroom instructor service.</param>
        /// <param name="providerProfileExtraService">The provider profile extra service.</param>
        /// <param name="commentService">The comment service.</param>
        /// <param name="providerSelectionService">The provider selection service.</param>
        public SubmissionController(IProviderService providerService, IProviderApplicationService providerApplicationService, IProcessControlService processControlService, IFormDataService formDataService, IClassroomInstructorService classroomInstructorService, IProviderProfileExtraService providerProfileExtraService, ICommentService commentService, IProviderSelectionService providerSelectionService)
        {
            this._providerService = providerService;
            this._providerApplicationService = providerApplicationService;
            this._processControlService = processControlService;
            this._formDataService = formDataService;
            this._classroomInstructorService = classroomInstructorService;
            this._providerProfileExtraService = providerProfileExtraService;
            this._commentService = commentService;
            this._providerSelectionService = providerSelectionService;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="SubmissionController"/> class.
        /// </summary>
        /// <param name="providerService">The provider service.</param>
        public SubmissionController(IProviderService providerService)
        {
            this._providerService = providerService;
        }

        public SubmissionController(IProviderService _providerService1, IProviderApplicationService _providerApplicationService1, IProcessControlService _processControlService1, IFormDataService _formDataService1, IClassroomInstructorService _classroomInstructorService1)
        {
            this._providerService1 = _providerService1;
            this._providerApplicationService1 = _providerApplicationService1;
            this._processControlService1 = _processControlService1;
            this._formDataService1 = _formDataService1;
            this._classroomInstructorService1 = _classroomInstructorService1;
        }

        /// <summary>
        /// Generates the view for the Index action.
        /// </summary>
        /// <param name="id">The identifier.</param>
        /// <returns>The action result for the view.</returns>
        [SessionExpireFilter]
        [NotAvailableInMaintenanceMode]
        public ActionResult Index(int? id)
        {
            var applicationViewModel = new ApplicationViewModel();
            
            var providerApplication = this.GetLatestProviderApplication(id);

            var bo = new ProviderApplicationBO(providerApplication);

            bo.CheckAccess(this.User);

            // If we have an actual provider application continue on
            if (providerApplication != null)
            {
                if (this.CurrentUserHasAccessToApplication(providerApplication))
                {
                    Session["ProviderProfileId"] = providerApplication.ProviderProfileId.Value;
                    Session["ProviderApplicationId"] = providerApplication.ProviderApplicationId.Value;
                    Session["FormDataId"] = providerApplication.FormDataId.Value;
                    Session["ProviderApplicationTypeId"] = providerApplication.ProviderApplicationTypeId;

                    // Build our return model
                    applicationViewModel.AcknowledgementViewModel = new AcknowledgementViewModel();
                    applicationViewModel.AcknowledgementViewModel.ProviderName = providerApplication.Profile.ProviderName;
                    applicationViewModel.AcknowledgementViewModel.CoalitionName = providerApplication.Profile.ELCCoalitionName;
                    applicationViewModel.AcknowledgementViewModel.ProviderAddress = providerApplication.Profile.LocationAddress;

                    // Get the prior year application data to prepop acknowledgment contact info
                    var priorProviderApplication = new ProviderApplicationDTO();
                    providerApplication.ProgramYearId = providerApplication.Profile.ProgramYearId;
                    priorProviderApplication = _providerApplicationService.ListPreviousProviderApplications(providerApplication).FirstOrDefault(y => y.ProgramYearId == providerApplication.ProgramYearId - 1);

                    if (string.IsNullOrEmpty(providerApplication.ContactName) && priorProviderApplication != null)
                    {
                        applicationViewModel.AcknowledgementViewModel.ContactName = priorProviderApplication.ContactName;
                    }
                    else
                    {
                        applicationViewModel.AcknowledgementViewModel.ContactName = providerApplication.ContactName;
                    }

                    if (string.IsNullOrEmpty(providerApplication.ContactEmail) && priorProviderApplication != null)
                    {
                        applicationViewModel.AcknowledgementViewModel.ContactEmail = priorProviderApplication.ContactEmail;
                    }
                    else
                    {
                        applicationViewModel.AcknowledgementViewModel.ContactEmail = providerApplication.ContactEmail;
                    }

                    if (string.IsNullOrEmpty(providerApplication.ContactTitle) && priorProviderApplication != null)
                    {
                        applicationViewModel.AcknowledgementViewModel.ContactTitle = priorProviderApplication.ContactTitle;
                    }
                    else
                    {
                        applicationViewModel.AcknowledgementViewModel.ContactTitle = providerApplication.ContactTitle;
                    }
                    //applicationViewModel.AcknowledgementViewModel.ContactName = providerApplication.ContactName;
                    //applicationViewModel.AcknowledgementViewModel.ContactTitle = providerApplication.ContactTitle;
                    //applicationViewModel.AcknowledgementViewModel.ContactEmail = providerApplication.ContactEmail;
                    applicationViewModel.ProgramYearId = Convert.ToInt32(providerApplication.Profile.ProgramYearId);
                    dynamic x = Newtonsoft.Json.JsonConvert.DeserializeObject(providerApplication.ScreeningData);
                    foreach (var item in x)
                    {
                        if (item.Name == "AttendingCount")
                        {
                            applicationViewModel.FormViewModel.AttendingCount = item.Value;
                        }
                    }

                    // Pass this value along to our client-side
                    RequireJsOptions.Add("providerApplicationId", providerApplication.ProviderApplicationId);
                    RequireJsOptions.Add("formDataId", providerApplication.FormDataId.Value);                    
                }
                else
                {
                    throw new AccessDeniedException();
                }
            }

            return View(applicationViewModel);
        }

        /// <summary>
        /// Generates the view for the Confirmation action.
        /// </summary>
        /// <returns>The action result for the view.</returns>
        public ActionResult Confirmation()
        {
            return this.View();
        }

        /// <summary>
        /// Generates the view for the Contact Elc action.
        /// </summary>
        /// <returns>The action result for the view.</returns>
        public ActionResult ContactElc()
        {
            return this.View();
        }

        /// <summary>
        /// Generates the view for the Screening action.
        /// </summary>
        /// <returns>The action result for the view.</returns>
        [SessionExpireFilter]
        [NotAvailableInMaintenanceMode]
        public ActionResult Screening()
        {
            var providerApplication = this.GetLatestProviderApplication(null);

            var bo = new ProviderApplicationBO(providerApplication);

            bo.CheckAccess(this.User);

            // If we have an actual provider application continue on
            if (providerApplication != null)
            {
                if (this.CurrentUserHasAccessToApplication(providerApplication))
                {
                    Session["ProviderProfileId"] = providerApplication.ProviderProfileId.Value;
                    Session["ProviderApplicationId"] = providerApplication.ProviderApplicationId.Value;
                    Session["FormDataId"] = providerApplication.FormDataId.Value;
                    Session["ProviderApplicationTypeId"] = providerApplication.ProviderApplicationTypeId;
                }
                else
                {
                    throw new AccessDeniedException();
                }
            }

            return View();
        }

        /// <summary>
        /// Generates the view for the Screening action.
        /// </summary>
        /// <param name="model">The model.</param>
        /// <returns>The action result for the view.</returns>
        [HttpPost]
        [ValidateAntiForgeryToken]
        [SessionExpireFilter]
        public ActionResult Screening(ScreeningModel model)
        {
            if (ModelState.IsValid)
            {
                var screening = new ProviderApplicationScreeningDTO();

                screening.ProviderApplicationId = Convert.ToInt32(Session["ProviderApplicationId"]);
                screening.ActiveSchoolReadinessContract = model.ActiveSchoolReadinessContract == "Yes";
                screening.AllInstructorsHaveAgreed = model.AllInstructorsHaveAgreed == "Yes";
                screening.AttendingCount = model.AttendingCount;
                screening.BirthTo5YearOldReadinessCount = model.BirthTo5YearOldReadinessCount;

                var errorMessages = this._providerApplicationService.ScreenProviderApplication(screening);
                model.ErrorMessages = errorMessages;

                if (string.IsNullOrEmpty(errorMessages))
                {
                    return View("Eligible");
                }

                return View("NotEligible", model);
            }

            return View("Screening", model);
        }

        /// <summary>
        /// The start or resume action method.
        /// </summary>
        /// <returns>The result of the action.</returns>
        [NotAvailableInMaintenanceMode]
        public ActionResult Go()
        {
            var model = new GoViewModel();

            var providerApplicationId = Convert.ToInt32(Session["ProviderApplicationId"]);

            if (providerApplicationId <= 0)
            {
                model.Heading = "Welcome!";
                model.Introduction = "It looks like you're starting a new application submission.";
                model.ActionText = "Start A New Application Submission";
            }
            else
            {
                model.Heading = "Welcome Back!";
                model.Introduction = "It looks like an application is already started.";
                model.ActionText = "Resume Application";
            }

            model.ActionLink = Url.Action("Index");

            return View(model);
        }

        /// <summary>
        /// The review status action method.
        /// </summary>
        /// <param name="id">The provider application id</param>
        /// <returns>The result of the action.</returns>
        [SessionExpireFilter]
        public ActionResult ReviewStatus(int id)
        {
            var model = new ReviewStatusViewModel();

            var providerApplicationCriteria = new ProviderApplicationDTO();
            providerApplicationCriteria.ProviderApplicationId = id;

            // Search the existing provider applications, using the provider profile id and template form id
            var providerApplication = _providerApplicationService.ReadProviderApplication(providerApplicationCriteria);
            if (providerApplication != null)
            {
                var bo = new ProviderApplicationBO(providerApplication);

                bo.CheckAccess(this.User);

                model.ProviderApplication = providerApplication;

                var providerProfileCriteria = new ProviderProfileDTO();
                providerProfileCriteria.ProviderProfileId = providerApplication.ProviderProfileId;

                var providerProfiles = _providerService.SearchProviderProfiles(providerProfileCriteria);
                model.ProviderProfile = providerProfiles.First();

                var availableBusinessProcessQueryCriteria = new AvailableBusinessProcessQueryDTO() {
                    AsOfDate = DateTime.Now,
                    BusinessProcessType = BusinessProcessType.BenchmarkAccess,
                    Roles = new[] { BusinessRole.Provider },
                    ProgramYearId = providerProfiles.First().ProgramYearId
                };
                var currentBenchmarkWindows = _processControlService.SearchAvailableBusinessProcesses(availableBusinessProcessQueryCriteria);

                var currentProviderSelectionWindows = _processControlService.SearchAvailableBusinessProcesses(new AvailableBusinessProcessQueryDTO()
                {
                    AsOfDate = DateTime.Now,
                    BusinessProcessType = BusinessProcessType.ProviderSelection,
                    Roles = new[] { BusinessRole.Provider },
                    ProgramYearId = providerProfiles.First().ProgramYearId
                });

                // If the BM phase is the only open window and the provider's application is Potentially 
                // Eligible - Alternate or Not Reviewed, assume they will not be apart of the program year.
                if (currentBenchmarkWindows.Any() && !currentProviderSelectionWindows.Any())
                {
                    if (providerApplication.ReviewStatus == ApplicationReviewStatus.NotReviewed ||
                        providerApplication.ReviewStatus == ApplicationReviewStatus.PotentiallyEligibleAlternate)
                    {
                        model.ProviderApplication.ReviewStatus = ApplicationReviewStatus.NotSelected;
                    }

                    if (providerApplication.ReviewStatus == ApplicationReviewStatus.PotentiallyEligible)
                    {
                        var providerSelectionCriteria = new ProviderSelectionDTO()
                        {
                            Profile = providerProfiles.First()
                        };
                        var selectedProviderSelection = _providerSelectionService.ReadProviderSelection(providerSelectionCriteria);

                        if (selectedProviderSelection != null && selectedProviderSelection.ProviderSelectionStatusId == (int)ProviderSelectionStatus.NotSelected)
                        {
                            model.ProviderApplication.ReviewStatus = ApplicationReviewStatus.NotSelected;
                        }
                    }
                }

            }

            return View(model);
        }

        /// <summary>
        /// Generates the view for the WindowExpired action.
        /// </summary>
        /// <param name="id">The identifier.</param>
        /// <returns>The action result for the view.</returns>
        [SessionExpireFilter]
        public ActionResult WindowExpired(int? id)
        {
            var model = new WindowExpiredViewModel();

            ViewBag.NotSelected = true;

            Session["NotSelected"] = true;

            if (id.HasValue)
            {
                var providerApplicationCriteria = new ProviderApplicationDTO();
                providerApplicationCriteria.ProviderApplicationId = id;

                // Search the existing provider applications, using the provider profile id and template form id
                var providerApplication =
                    _providerApplicationService.ReadProviderApplication(providerApplicationCriteria);
                if (providerApplication != null)
                {
                    var bo = new ProviderApplicationBO(providerApplication);

                    bo.CheckAccess(this.User);

                    model.ProviderApplication = providerApplication;
                    model.ProviderApplicationId = providerApplication.ProviderApplicationId.Value;

                    var providerProfileCriteria = new ProviderProfileDTO();
                    providerProfileCriteria.ProviderProfileId = providerApplication.ProviderProfileId;

                    var providerProfiles = _providerService.SearchProviderProfiles(providerProfileCriteria);
                    model.ProviderProfile = providerProfiles.First();

                    var availableEnd = Session["AvailableEnd"] as DateTime?;
                    if (availableEnd.HasValue)
                    {
                        model.AvailableEnd = availableEnd.Value;
                    }
                }
            }
            else
            {
                model.ProviderApplication = new ProviderApplicationDTO();
                model.ProviderApplication.SubmissionStatusDate = TimeProvider.Current.Now;

                var providerProfileCriteria = new ProviderProfileDTO();
                providerProfileCriteria.ProviderId = this.ProviderId;

                var providerProfiles = _providerService.SearchProviderProfiles(providerProfileCriteria);
                model.ProviderProfile = providerProfiles.First();

                var availableEnd = Session["AvailableEnd"] as DateTime?;
                if (availableEnd.HasValue)
                {
                    model.AvailableEnd = availableEnd.Value;
                }
            }

            return View(model);
        }

        /// <summary>
        /// Generates the view for the GetApplicationAsWordDocument action.
        /// </summary>
        /// <param name="id">The identifier.</param>
        /// <returns>The action result for the view.</returns>
        public ActionResult Export(int id)
        {
            var model = this.GetDetailsViewModel(id);

            ViewBag.Title = "Export";

            var htmlResult = this.RenderActionResultToString(View("Export", model));

            //get program year description for file name            
            var criteria = new ProviderApplicationDTO();
            criteria.ProviderApplicationId = id;
            var provApp = _providerApplicationService.ReadProviderApplication(criteria);
            var pyDesc = string.Empty;
            var programYears = LookupCache.GetProgramYears();
            foreach (var py in programYears)
            {
                if (py.ProgramYearId == provApp.ProgramYearId)
                {
                    pyDesc = py.ProgramYearDesc;
                    break;
                }
            }

            var fileName = string.Format(
                        pyDesc + "_ProviderApplication_{0}_{1}.doc",
                        model.ProviderID,
                        model.ProviderApplicationId);

            var fileContents = Encoding.UTF8.GetBytes(htmlResult);

            return this.File(fileContents, "application/vnd.ms-word", fileName);
        }

        /// <summary>
        /// Gets the details view model.
        /// </summary>
        /// <param name="id">The identifier.</param>
        /// <returns>The view model.</returns>
        private ReviewDetailsViewModel GetDetailsViewModel(int id)
        {
            // Get the application data
            var providerApplication = new ProviderApplicationDTO();
            providerApplication.ProviderApplicationId = id;

            providerApplication = _providerApplicationService.ReadProviderApplication(providerApplication);

            var bo = new ProviderApplicationBO(providerApplication);

            bo.CheckAccess(this.User);

            // Get form data
            var formDataCriteria = new FormDataQueryDTO();
            formDataCriteria.FormDataId = providerApplication.FormDataId.Value;

            var formData = _formDataService.ReadFormDataDetails(formDataCriteria);

            var serializer = new JavaScriptSerializer();
            var formViewModel = serializer.Deserialize<FormViewModel>(serializer.Serialize(formData));

            // Get profile data
            var profile = new ProviderProfileDTO();
            profile.ProviderProfileId = providerApplication.ProviderProfileId;
            profile = this._providerService.SearchProviderProfiles(profile).FirstOrDefault();

            // Get the provider profile extra data
            var profileExtra = new ProviderProfileExtraDTO();
            profileExtra.ProviderProfileId = providerApplication.ProviderProfileId;
            profileExtra = this._providerProfileExtraService.ReadProviderProfileExtra(profileExtra);

            // get comments
            var commentCriteria = new CommentDTO();
            commentCriteria.LinkId = id;
            commentCriteria.LinkTypeId = (int)LinkType.ProviderApplication;

            var comments = _commentService.ReadCommentList(commentCriteria);

            // Build our return model
            var applicationViewModel = new ApplicationViewModel();
            applicationViewModel.ProgramYearId = providerApplication.ProgramYearId.Value;

            // Get the provider profile contact information
            var contactInformation = this._providerService.ReadProviderContactInfo(profile);

            applicationViewModel.ProfileViewModel.ProviderContactName = contactInformation.ContactName;
            applicationViewModel.ProfileViewModel.ProviderContactPhone = contactInformation.ContactPhone;
            applicationViewModel.ProfileViewModel.ProviderContactEmail = contactInformation.ContactEmail;

            applicationViewModel.AcknowledgementViewModel = new AcknowledgementViewModel();
            applicationViewModel.AcknowledgementViewModel.ContactName = providerApplication.ContactName;
            applicationViewModel.AcknowledgementViewModel.ContactEmail = providerApplication.ContactEmail;
            applicationViewModel.AcknowledgementViewModel.ContactTitle = providerApplication.ContactTitle;

            applicationViewModel.FormViewModel = formViewModel;

            applicationViewModel.InstructorViewModel = new InstructorViewModel
            {
                Instructors = this._classroomInstructorService.SearchInstructors(new InstructorDTO
                {
                    ProviderProfileId = profile.ProviderProfileId
                })
            };

            applicationViewModel.ClassroomViewModel = new ClassroomViewModel
            {
                Classrooms = this._classroomInstructorService.SearchClassrooms(new ClassroomDTO
                {
                    ProviderProfileId = profile.ProviderProfileId
                })
            };

            applicationViewModel.ClassroomInstructorsViewModel = new ClassroomInstructorsViewModel
            {
                ClassroomInstructors = new List<ClassroomInstructorDTO>()
            };

            // Get associations and flatten our the relationship
            foreach (var instructor in applicationViewModel.InstructorViewModel.Instructors)
            {
                var classroomInstructors = this._classroomInstructorService.ListForInstructor(new ClassroomInstructorDTO
                {
                    Instructor = instructor,
                    ProviderProfileId = instructor.ProviderProfileId
                });

                foreach (var cassroomInstructor in classroomInstructors)
                {
                    var assignment = new ClassroomInstructorDTO
                    {
                        Instructor = instructor,
                        Classroom = cassroomInstructor.Classroom,
                        LeadInstructor = cassroomInstructor.LeadInstructor
                    };

                    if (assignment != null)
                    {
                        applicationViewModel.ClassroomInstructorsViewModel.ClassroomInstructors.Add(assignment);
                    }

                }
            }

            var model = new ReviewDetailsViewModel();
            var statusModel = new ReviewStatusModel(this.Role, providerApplication);

            model.ProviderID = providerApplication.ProviderId.ToString();
            model.ProviderApplicationId = providerApplication.ProviderApplicationId.Value;

            if (comments != null)
            {
                model.CommentList = comments.ToList();
            }

            if (providerApplication.SubmissionStatus == ApplicationSubmissionStatus.AccessDenied &&
                !string.IsNullOrEmpty(providerApplication.ScreeningData))
            {
                model.Screening =
                    DOE.OELPFP.Common.Serialization.JsonSerializer.DeserializeFromString<ProviderApplicationScreeningDTO>(
                        providerApplication.ScreeningData);
            }

            model.PovertyTract = (bool)profile.IsPovertyTract ? "Yes" : "No";

            model.SubmissionStatus = providerApplication.SubmissionStatus.GetValueOrDefault();
            model.SubmissionStatusDate = providerApplication.SubmissionStatusDate;
            model.FormattedSubmissionStatus = statusModel.FormattedSubmissionStatus;

            if (providerApplication.SubmissionStatus == ApplicationSubmissionStatus.Completed && providerApplication.ReviewStatus.HasValue)
            {
                model.ReviewStatus = providerApplication.ReviewStatus.Value;
                model.ReviewStatusDate = providerApplication.ReviewStatusDate;
                model.FormattedReviewStatus = statusModel.FormattedReviewStatus;
            }

            model.Application = applicationViewModel;

            if (profile != null)
            {
                model.ELCCoalitionId = profile.ELCCoalitionId.Value;
                model.ELCCoalitionName = profile.ELCCoalitionName;
                applicationViewModel.AcknowledgementViewModel.ProviderName = profile.ProviderName;

                if (profile.EligibilityOverrideDate.HasValue)
                {
                    model.Screening =
                        DOE.OELPFP.Common.Serialization.JsonSerializer.DeserializeFromString<ProviderApplicationScreeningDTO>(
                            providerApplication.ScreeningData);

                    model.EligibilityOverrideDate = profile.EligibilityOverrideDate;
                    model.EligibilityOverrideUser = profile.EligibilityOverrideUser;
                }

                model.SelectedProgramYearId = Convert.ToInt32(profile.ProgramYearId);
            }

            // Load the extra fields
            if (profileExtra != null)
            {
                applicationViewModel.ProfileViewModel.IsGoldSeal = (bool)profileExtra.IsGoldSeal;
                applicationViewModel.ProfileViewModel.AccreditingAssociation = profileExtra.AccreditingAssociation;
                applicationViewModel.ProfileViewModel.OtherAccreditingAssociation = profileExtra.OtherAccreditingAssociation;
                applicationViewModel.ProfileViewModel.IsLicenseExempt = profileExtra.LicenseExempt;
                applicationViewModel.ProfileViewModel.ChildAssessmentSystem = profileExtra.ChildAssessmentSystem;
                applicationViewModel.ProfileViewModel.IsInQRIS = profileExtra.IsInQRIS;
            }

            if ((User.IsInRole(BusinessRole.OELReviewer) || User.IsInRole(BusinessRole.Administrator)) && Session["ApplicationSearch:iELCCoalitionId"] != null)
            {
                model.SelectedCoalitionId = Convert.ToInt32(Session["ApplicationSearch:iELCCoalitionId"]);
            }
            else
            {
                model.SelectedCoalitionId = model.ELCCoalitionId;
            }

            // Get all of the previous applications for the provider
            var previousApplications = _providerApplicationService.ListPreviousProviderApplications(new ProviderApplicationDTO
            {
                ProviderId = profile.ProviderId,
                ProgramYearId = profile.ProgramYearId
            });

            foreach (var prevApp in previousApplications)
            {
                model.PreviousApplications.Add(new PreviousApplicationReviewDetailViewModel
                {
                    ProgramYearDesc = prevApp.ProgramYearDesc,
                    HasApplication = prevApp.ProviderApplicationId.HasValue,
                    AppReviewStatus = prevApp.ReviewStatus
                });
            }

            //determine if application selection window is open
            var processControlService = new ProcessControlService();

            var applicationReviewQuery = new AvailableBusinessProcessQueryDTO();

            applicationReviewQuery.Roles = new[] { BusinessRole.Coalition };
            applicationReviewQuery.BusinessProcessType = BusinessProcessType.Review;

            var applicationReviewControls =
                processControlService.SearchAvailableBusinessProcesses(applicationReviewQuery)
                    .Where(x => x.ProviderApplicationTypeId == this.ProviderApplicationTypeId)
                    .OrderByDescending(x => x.AvailableStart)
                    .ToList();

            var applicationReviewControl =
                applicationReviewControls.FirstOrDefault(
                    x => x.AvailableStart <= DateTime.Now && (x.AvailableEnd == null || x.AvailableEnd > DateTime.Now));

            if (applicationReviewControl == null)
            {
                model.IsApplicationSelectionWindowOpen = false;
            }
            else
            {
                model.IsApplicationSelectionWindowOpen = true;
            }

            //determine if application submission window is open

            var applicationSubmitQuery = new AvailableBusinessProcessQueryDTO();

            applicationSubmitQuery.Roles = new[] { BusinessRole.Provider };
            applicationSubmitQuery.BusinessProcessType = BusinessProcessType.Create;

            var applicationSubmitControls =
                processControlService.SearchAvailableBusinessProcesses(applicationSubmitQuery)
                    .OrderByDescending(x => x.AvailableStart)
                    .ToList();

            var applicationSubmitControl =
                applicationSubmitControls.FirstOrDefault(
                    x => x.AvailableStart <= DateTime.Now && (x.AvailableEnd == null || x.AvailableEnd > DateTime.Now));

            if (!(applicationSubmitControl == null) && profile.IsCurrentProgramYear)
            {
                model.IsApplicationSubmissionWindowOpen = true;
            }
            else
            {
                model.IsApplicationSubmissionWindowOpen = false;
            }

            return model;
        }

        /// <summary>
        /// Get the latest provider application.
        /// This thing will go away soon probably in favor of service-layer alternative.
        /// </summary>
        /// <param name="id">The identifier.</param>
        /// <returns>Provider application dto</returns>
        private ProviderApplicationDTO GetLatestProviderApplication(int? id)
        {
            ProviderApplicationDTO providerApplication = null;

            var providerCriteria = new ProviderDTO();

            if (User.IsInRole(BusinessRole.Provider))
            {
                providerCriteria.ProviderId = this.ProviderId;
            }
            else
            {
                providerCriteria.ProviderId = id ?? 0;
            }

            var availableApplicationTypesQuery = GetAvailableApplicationTypesQuery(BusinessProcessType.Create);

            var applicationTypes = _processControlService.GetAvailableApplicationTypes(availableApplicationTypesQuery);

            if (applicationTypes.Count > 0)
            {
                var firstApplicationType = applicationTypes.First();

                // gives provider profile id (this ties to the application...every page)
                var providerProfileCriteria = new ProviderProfileDTO();
                providerProfileCriteria.ProgramYearId = firstApplicationType.ProgramYearId;
                providerProfileCriteria.ProgramTypeId = firstApplicationType.ProgramTypeId;
                providerProfileCriteria.ProviderId = providerCriteria.ProviderId;

                var providerProfiles = _providerService.SearchProviderProfiles(providerProfileCriteria);

                // If we have at least one provider profile continue on
                if (providerProfiles.Count > 0)
                {
                    // Get the first provider profile (there should be only one)
                    var firstProviderProfile = providerProfiles.First();

                    var providerApplicationCriteria = new ProviderApplicationDTO();
                    providerApplicationCriteria.ProviderId = firstProviderProfile.ProviderId;
                    providerApplicationCriteria.ProviderProfileId = firstProviderProfile.ProviderProfileId;
                    providerApplicationCriteria.ProviderApplicationTypeId = firstApplicationType.ProviderApplicationTypeId;

                    // Search the existing provider applications, using the provider profile id and template form id
                    var providerApplications = _providerApplicationService
                        .SearchProviderApplications(providerApplicationCriteria)
                        .Where(x => x.SubmissionStatus != ApplicationSubmissionStatus.Abandoned)
                        .ToList();

                    // If we have at least one provider application continue
                    if (providerApplications.Count > 0)
                    {
                        // Get the first provider application
                        providerApplication = providerApplications.First();
                    }
                    else
                    {
                        // If null, create a new application
                        var applicationToAdd = new ProviderApplicationDTO();
                        applicationToAdd.ProviderId = providerApplicationCriteria.ProviderId;
                        applicationToAdd.ProviderProfileId = providerApplicationCriteria.ProviderProfileId;
                        applicationToAdd.TemplateFormId = providerApplicationCriteria.TemplateFormId;
                        applicationToAdd.ProviderApplicationTypeId = providerApplicationCriteria.ProviderApplicationTypeId;


                        var importDto = _providerApplicationService.GetDataFileImportInfo(providerApplicationCriteria.ProviderId, firstProviderProfile.ProgramYearId);
                        applicationToAdd.ContactName = importDto.SubmitterName;
                        applicationToAdd.ContactTitle = importDto.SubmitterTitle;
                        applicationToAdd.ContactEmail = importDto.SubmitterEmail;
                        applicationToAdd.ProgramYearId = firstProviderProfile.ProgramYearId;

                        providerApplication = _providerApplicationService.AddNewApplication(applicationToAdd);

                    }

                    providerApplication.Profile = firstProviderProfile;
                }
            }

            return providerApplication;
        }

        /// <summary>
        /// Determines if the currently logged-in user can access this application.
        /// This thing will go away soon probably in favor of service-layer alternative.
        /// </summary>
        /// <param name="providerApplication">The requested provider application.</param>
        /// <returns>True if yes, false otherwise.</returns>
        private bool CurrentUserHasAccessToApplication(ProviderApplicationDTO providerApplication)
        {
            return true;
        }
    }
}
