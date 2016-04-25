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