String htmlOpen = 
"<!DOCTYPE html>"
  "<html>"
    "<head>"
      "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\">"
    "</head>"
    "<body>"
      "<div class=\"container centered\">"
        "<h2>Make radio relays smarter</h2>";

String htmlClose =
      "</div>"
    "</body>"
  "</html>";

String htmlSwitchButtonGroup(String switchName, bool currentValue){
  return  
  "<div class=\"btn-group\">" //bootstrap button group div
    "<a href=\"/" + switchName + "/1\" class=\"btn " + (currentValue ? "btn-success\">" : "btn-primary\">") + //use css style to show switch status
      switchName + " ON"
    "</a>"
    "<a href=\"/" + switchName + "/0\" class=\"btn " + (!currentValue ? "btn-success\">" : "btn-primary\">") + //use css style to show switch status
      switchName + " OFF"
    "</a>"
  "</div>"
  "<br>"
  "<br>";
}



