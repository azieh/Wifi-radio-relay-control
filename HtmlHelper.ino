String htmlHead1 = "<!DOCTYPE html><html><head>";
String htmlLoadBootstrapCss = "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css>";
String htmlHead2 = "</head><body><h2>Make radio relays smarter</h2>";
String htmlEnd = "</body>\r\n</html>\n;";

String htmlSwitchButtonGroup(String switchName, bool currentValue){
  String buttonBuilder = "<div class=\"btn-group\">"; //bootstrap button group div
  buttonBuilder +="<a href=\"/";
  buttonBuilder += switchName + "/" + "1" + "#\" "; // turn on request
  buttonBuilder += "class=\"btn " + (currentValue) ? "btn-primary\">" : "\">"; //use css style to show switch status
  buttonBuilder += switchName + " ON";
  buttonBuilder += "</a>";
  buttonBuilder +="<a href=\"/";
  buttonBuilder += switchName + "/" + "0" + "#\" "; // turn off request
  buttonBuilder += "class=\"btn " + (currentValue) ? "\">" : "btn-primary\">"; //use css style to show switch status
  buttonBuilder += switchName + " OFF";
  buttonBuilder += "</a>";
  buttonBuilder += "</div> </ br> </ br>";
}



