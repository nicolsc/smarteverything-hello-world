#SIGFOX first message using the SmartEverything


Using the [SmartEverything](http://smarteverything.it) Arduino board and its SIGFOX-ready [Telit](http://www.telit.com/products/product-service-selector/product-service-selector/show/product/le51-868-s/) module, send a test message every 10 minutes over the [SIGFOX](http://makers.sigfox.com) network.

##Prerequisites
###SmartEverything
Install the core Arduino libraries:  

* Tools > Boards > Board Manager
* Install the Arduino Zero core
* Install the ASME core (filter=Partner)

You should use the board type _Smart Everything FOX (Native USB)_

###SIGFOX
To check your messages, you must register your board first

Go to [the SIGFOX cloud](http://backend.sigfox.com/activate) & enter the needed informations : ID & PAC (secret code) associated to your module
	
##Go Further
###Useful program

Sending a test message is nice, but once it's done you may  be interested by sending *real* data.  
As the Smart Everything is loaded with a lot of sensors, you can quickly build something great.  
Check out [this example](https://github.com/nicolsc/sigfox-weather-station) to send the temperature, atmospheric pressure & humidity level.
