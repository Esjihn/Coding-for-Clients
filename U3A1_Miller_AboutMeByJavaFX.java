import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.text.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.geometry.Insets;
import javafx.scene.layout.FlowPane;



public class U3A1_Miller_AboutMeByJavaFX extends Application {
    
    @Override
    
    public void start(Stage primaryStage) {
        
    FlowPane flow = new FlowPane();
        
        
    
            
        flow.setPadding(new Insets(50, 50, 50, 50));
        
           
        Image IM1 = new Image("FavSport.jpg");
        
        Image IM2 = new Image("Matt.jpg");
        
        Text text1 = new Text("Matthew D. Miller");

        text1.setFont(Font.font("Courier", FontWeight.BOLD, FontPosture.ITALIC, 25));
        
        Text text2 = new Text("Protein Bars");

        text2.setFont(Font.font("Courier", FontWeight.BOLD, FontPosture.ITALIC, 25));
        
        flow.setVgap(10);
        flow.setHgap(190);
        flow.setPrefWrapLength(100);
        
        flow.getChildren().add(text1);        
        flow.getChildren().add(new ImageView(IM2));
        flow.getChildren().add(new ImageView(IM1));
        flow.getChildren().add(text2);
        
        
        Scene scene = new Scene(flow, 855, 675);
        
        primaryStage.setTitle("About Me by JavaFX!");

        primaryStage.setScene(scene);
          
        primaryStage.show();

    }
    
    
    
    public static void main(String[] args) {
        
        System.out.println("Miller's Copy");
        
        launch(args);
        
    }
    
}
