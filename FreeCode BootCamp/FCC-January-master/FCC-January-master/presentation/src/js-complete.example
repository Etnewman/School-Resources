// This is Cookeville's location
const COOKEVILLE ={
	latitude: 36.1628,
	longitude: -85.5016
};

// This is the weather API url
// I chose to make it a function rather than a static variable to make it easier to use
const WEATHER_API_URL = (latitude = COOKEVILLE.latitude, longitude = COOKEVILLE.longitude)=>`https://fcc-weather-api.glitch.me/api/current?lat=${latitude}&lon=${longitude}`;

// This function is responsible for hitting the location API and getting our location
const getLocation = () =>{
	return new Promise(resolve => {
		navigator.geolocation.getCurrentPosition(position => resolve(position));
	});
}

// This function will convert to Fahrenheit for us simple Americans
const celsiusToFahrenheit = (celsius) =>{
	return Math.round(celsius * 9 / 5 + 32);
}

// This function should run through these steps:
// 1. Get the user's location
// 2. Get the weather
// 4. Update the UI
const updateWeather = async () => {
	let location = COOKEVILLE;
	// Check if the user has location enabled
	if(Object.entries(navigator.geolocation).length > 0){
		// If they do, we can change the location object based on their location
		const position = await getLocation();
		location = {
			latitude: position.coords.latitude,
			longitude: position.coords.longitude
		}
	}
	// If not, the location defaults to Cookeville

	// Now we use that location object to hit our API
	const res = await fetch(WEATHER_API_URL(location.latitude, location.longitude));
	const weather = await res.json();

	// Finally, we have everything we need to update the UI
	weatherName.innerHTML = weather.name;
	weatherTemp.innerHTML = celsiusToFahrenheit(weather.main.temp);
	weatherLow.innerHTML = celsiusToFahrenheit(weather.main.temp_min);
	weatherHigh.innerHTML = celsiusToFahrenheit(weather.main.temp_max);
}

// This is our hour interval
const HOUR = 1 * 60 * 60 * 1000;
setInterval(updateWeather, HOUR);

const weatherName = document.querySelector('#weather-name');
const weatherTemp = document.querySelector('#weather-temp');
const weatherLow = document.querySelector('#weather-low');
const weatherHigh = document.querySelector('#weather-high');

// The first thing we do is run the update the weather
updateWeather();