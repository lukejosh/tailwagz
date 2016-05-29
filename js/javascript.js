// Function: validate_password()
// Description: a simple function to check that two password match
// and display a useful message
// Input: none
// Output: none
function validate_password() {
    var password = document.getElementById("password");
    var confPass = document.getElementById("confpassword");

	// If password do not match then show validity message
    if (password.value != confPass.value) {
        confPass.setCustomValidity("Password do not match");
    }
    else {
        confPass.setCustomValidity('');
    }
}

// Function: initMap()
// Description: a function to set up an empty map
// Input: none
// Output: none
function initMap() {
	// Create a location array for any location (doesn't matter where)
	var myLatLng = {lat: -27.467401, lng: 153.025101};
	
	// Initialise map
	map = new google.maps.Map(document.getElementById('googleMap'), {
	  zoom: 10,
	  center: myLatLng,
	  mapTypeId: google.maps.MapTypeId.HYBRID
	});
	
	// Add bounds to map
	bounds = new google.maps.LatLngBounds();
}

// Function: addMarkerToMap(latitude,longitude,labelString,url,rating,suburb,street)
// Description: a function to add a park as a marker to the map
// Input: latitude,longitude,labelString,url,rating,suburb and street of park
// Output: none
function addMarkerToMap(latitude,longitude,labelString,url,rating,suburb,street){
	// Create a location array
	var myLatLng = {lat: parseFloat(latitude), lng: parseFloat(longitude)};
	
	// Create label for the marker 
	var contentString = "<h3><a href='"+url+"'>"+labelString+"</a></h3>"+
						"<b>Suburb: </>"+suburb+"<br/>"+
						"<b>Street: </>"+street+"<br/>"+
						"<b>Rating: </>"+rating+"<br/>";
	
	// Use label to create an info window in marker
	var infowindow = new google.maps.InfoWindow({
		content: contentString
	});

	// Create the marker
	var marker = new google.maps.Marker({
		position: myLatLng,
		map: map,
		title: contentString,
		url: url
	});
	
	// add a listener to open the info window when clicked
	marker.addListener('click', function() {
		infowindow.open(map, marker);
	});
	
	// Extend the bound of the map to include marker
	loc = new google.maps.LatLng(marker.position.lat(), marker.position.lng());
	bounds.extend(loc);
	
	// Fit and center the map to the bounds
	map.fitBounds(bounds);
	map.panToBounds(bounds);
}

// Function: revert_other_searches(keepid)
// Description: a function to reset all other search fields on change of another
// Input: the id of the field to be kept
// Output: none
function revert_other_searches(keepid){
    var elements = document.forms[0].elements;

	// Loop through each field 
    for(i = 0; i < elements.length; i++){
		//if id does not match the one to be kept or is not the submit button
        if(elements[i].type != "submit" && elements[i].id != keepid){
            //console.log(elements[i].type)
			// Reset option field 
            if(elements[i].type == "select-one"){
                elements[i].value = elements[i][0].value;
            }
			// Reset text field 
            else if(elements[i].type == "text"){
                elements[i].value = null;
            }
        }
    }
}

// Function: location_callback(loc)
// Description: a call back function used to redirect the user to a search by location results page 
// Input: the location of the user
// Output: none
function location_callback(loc) {
    window.location.href = "results.php?lat=".concat(loc.coords.latitude, "&lon=", loc.coords.longitude, "&distance=", document.getElementById("distance").value);
}

// Function: user_location_link()
// Description: a function to get the current location of the user and redirect to search results page
// Input: none
// Output: none
function user_location_link(){
    navigator.geolocation.getCurrentPosition(location_callback);
}