String htmlOpen = 
"<!DOCTYPE html>"
  "<html>"
    "<head>"
      "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\">"
    "</head>"
    "<body>"
      "<header class=\"header\">"
        "<div class=\"container centered\">"
          "<div class=\"row\">"
            "<div class=\"col-lg-10 mx-auto text-center\">"
              "<h2><strong>Make radio relays smarter</strong></h2>"
              "<ul class=\"list-unstyled\">";

String htmlClose =
              "</ul>"
            "</div>"
          "</div>"
        "</div>"
      "</header>"
    "</body>"
  "</html>";

String htmlSwitchButtonGroup(String switchName, bool currentValue){
  return
  "<li>"  
  "<div class=\"btn-group\">" //bootstrap button group div
    "<a href=\"/" + switchName + "/1\" class=\"btn btn-lg " + (currentValue ? "btn-success\">" : "btn-primary\">") + //use css style to show switch status
      switchName + " ON"
    "</a>"
    "<a href=\"/" + switchName + "/0\" class=\"btn btn-lg " + (!currentValue ? "btn-success\">" : "btn-primary\">") + //use css style to show switch status
      switchName + " OFF"
    "</a>"
  "</div>"
  "</li>";
}



