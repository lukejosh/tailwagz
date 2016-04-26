function templatemo_map() {
                $('.google-map').gmap3({
                    marker:{
                        address: '16.8496189,96.1288854' 
                    },
                        map:{
                        options:{
                        zoom: 15,
                        scrollwheel: false,
                        streetViewControl : true
                        }
                    }
                });
            }

function validate_password() {
    var password = document.getElementById("password")
    var confPass = document.getElementById("confpassword")

    if (password.value != confPass.value) {
        confPass.setCustomValidity("Passwords Don't Match");
    }

    else if (password.value.match(/\d+/g) == null) {
        confPass.setCustomValidity("Passwords must contain a digit")
    }
    else {
        confPass.setCustomValidity('')
    }
}

function initMap() {
	var myLatLng = {lat: -27.38123113, lng: 153.0436597};

	var map = new google.maps.Map(document.getElementById('googleMap'), {
	  zoom: 15,
	  center: myLatLng,
	  mapTypeId: google.maps.MapTypeId.SATELLITE
	});
	
	var contentString = "7th Brigade Park";
	
	var infowindow = new google.maps.InfoWindow({
		content: contentString
	});

	var marker = new google.maps.Marker({
		position: myLatLng,
		map: map,
		title: '7TH BRIGADE PARK'
	});
	marker.addListener('click', function() {
		infowindow.open(map, marker);
	});
}

function revert_other_searches(keepid){
    var elements = document.forms[0].elements;

    for(i = 0; i < elements.length; i++){
        if(elements[i].type != "submit" && elements[i].id != keepid){
            console.log(elements[i].type)
            if(elements[i].type == "select-one"){
                elements[i].value = elements[i][0].value;
            }
            else if(elements[i].type == "text"){
                elements[i].value = null;
            }
        }
    }
}