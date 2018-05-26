define(['knockout', 'xeditable', 'app/models/root/assignmentModel', 'app/models/root/classroomAssignmentModel', 'app/models/root/classroomModel'], function (ko, xeditable, AssignmentModel, ClassroomAssignmentModel, ClassroomModel) {
    var AssignmentListViewModel = function () {
        var _self = this;

        _self.stepName = "Assignments";
        _self.stepIconCssClass = "fa fa-random";
        _self.assignments = ko.observableArray([]);
        _self.selectedAssignee = ko.observable(null);
        _self.selectedAssignment = ko.observable({});
        _self.classroomData = ko.observableArray([]);
        _self.isGridEditable = ko.observable(true);
        _self.isAssignmentsEnabled = ko.observable(true);
        _self.isNewAssignment = ko.observable(false);
        _self.selectedIndex = 0;
        _self.isLoading = ko.observable(false);

        _self.rebindClassrooms = function () {
            $.get("/api/classroom", "", function (data) {
                data.classrooms = data.classrooms || [];

                _self.classroomData.removeAll();

                for (var i = 0; i < data.classrooms.length; i++) {
                    _self.classroomData.push(new ClassroomModel(data.classrooms[i]));
                }
            });
        };

        _self.rebindAssignments = function () {
            _self.isLoading(true);
            _self.selectedAssignment(new ClassroomAssignmentModel());
            _self.selectedAssignment.valueHasMutated();

            $.get("/api/classroominstructor", "", function (data) {
                _self.assignments.removeAll();

                for (var i = 0; i < data.length; i++) {
                    _self.assignments.push(new AssignmentModel(data[i]));
                }
                // Assignments are required for instructors as of 17-18
                for (var i = 0; i < _self.assignments().length; i++) {
                    if (!_self.assignments()[i].assignmentsMet()) {
                        $('.step-buttons > .btn-secondary').prop("disabled", true);
                        $('#divClassroomsRequired').show();
                        break;
                    }
                    $('.step-buttons > .btn-secondary').prop("disabled", false);
                    $('#divClassroomsRequired').hide();
                }

                // add red '*' for rows that need assignments
                for (var i = 0; i < _self.assignments().length; i++) {
                    if (!_self.assignments()[i].assignmentsMet()) {
                        $('#assignmentsGrid tr:eq(' + (i + 1) + ') td:last').append('*');
                        $('#assignmentsGrid tr:eq(' + (i + 1) + ') td:last').addClass('required');
                    }
                }

                _self.editAssignee(_self.assignments()[_self.selectedIndex]);

                $('html, body').animate({
                    scrollTop: $("#pfp-body-content").first().offset().top
                }, 1000);
            }).always(function () {
                _self.isLoading(false);
            });
        };
        
        _self.editAssignee = function (assignee) {
            if (_self.selectedAssignee() !== null) {
                _self.selectedAssignee().isSelected(false);
            }            

            // as of PY 17-18, Instructors will only be able to be assigned to one classroom
            if (assignee.hasAssignments() === 'Yes') {
                _self.isAssignmentsEnabled(false);
            }
            else {
                _self.isAssignmentsEnabled(true);
            }

            assignee.isSelected(true);

            if (_self.assignments().length > 0) {
                _self.selectedIndex = _self.assignments.indexOf(assignee);
            }            

            _self.selectedAssignee(assignee);
        };

        /**
        * Initializes application controls after each knockout template is rendered.
        */
        _self.initViewModel = function () {
            // Attach the jquery unobtrusive validator
            $.validator.unobtrusive.parse($("form"));
            // Initialize editable fields
            // For more information on how to use, see: http://vitalets.github.io/x-editable
            $.fn.editable.defaults.mode = 'inline';
            // For now let's not make anything editable 
            // $('.editable').editable();       

            $('.noEnterSubmit').keypress(function (e) {
                if (e.which == 13) {
                    e.preventDefault();
                }
            });

            _self.rebindAssignments();
            _self.rebindClassrooms();
        };

        _self.editClassroomAssignment = function (assignment) {
            _self.isNewAssignment(true);
            _self.enableForm(false);

            _self.selectedAssignment(new ClassroomAssignmentModel());
            _self.selectedAssignment.valueHasMutated();
            
            // No edit requirement currently.
        };

        _self.cancelEdit = function () {
            _self.isNewAssignment(false);
            _self.enableForm(true);
            _self.selectedAssignment(new ClassroomAssignmentModel());
            _self.selectedAssignment.valueHasMutated();
        };

        _self.validate = function () {
            if (_self.selectedAssignment().isFormValid() == true) {
                _self.saveRecord();
            }
        };

        _self.saveRecord = function () {
            var data;

            $('#saveButton').text('Please Wait...');
            $('#saveButton, #cancelButton').prop("disabled", true);

            data = $('form').serialize();

            $.post('/api/classroomInstructor/addAssignment?' + data, data, function (response) {
                // Hacky, but this pattern is not set up to handle responses like this.
                if (typeof response == 'string') {
                    _self.selectedAssignment().classroomMessage(response);
                } else {
                    _self.enableForm(true);
                    _self.isNewAssignment(false);
                    _self.rebindAssignments();
                }
            })
            .always(function () {
                $('#saveButton').text('Assign');
                $('#saveButton, #cancelButton').prop("disabled", false);
            });
        };    

        _self.enableForm = function (enable) {
            if (enable == true) {
                _self.isGridEditable(true);
                $('.step-buttons > button').prop("disabled", false);
            } else {
                _self.isGridEditable(false);
                $('.step-buttons > button').prop("disabled", true);
            }
        };

        _self.removeClassroomAssignment = function (classroomInstructorId, classroom) {
            $('#saveButton, #cancelButton').prop("disabled", true);
            
            $.post('/api/classroomInstructor/removeAssignment?classroomInstructorId=' + classroomInstructorId, {}, function (response) {
                _self.enableForm(true);
                _self.isNewAssignment(false);
                _self.rebindAssignments();
            })
            .always(function () {
                $('#saveButton').text('Assign');
                $('#saveButton, #cancelButton').prop("disabled", false);
            });
        };

        /**
        * Injects any view-specific rules for unobtrusive validation.
        * This is the object consumed by the rules event of jquery validation.
        */
        _self.validationRules = function () {
            return {}
        };

        /**
        * Handles view-specific logic for unobtrusive validation.
        * This is the function called by the submitHandler event of jquery validation.
        */
        _self.validationSubmitHandler = function (form) {

        };
    };

    return AssignmentListViewModel;
});