;=============================== 
; Conversion information
;=============================== 

;=============================== UNIT CONVERSION ==================================

; SPEED
; How to Convert Mile/hour to Kilometer/hour

; 1 mi/h = 1.609344 km/h
; 1 km/h = 0.6213711922 mi/h

; Example: convert 15 mi/h to km/h:
; 15 mi/h = 15 * 1.609344 km/h = 24.14016 km/h

; TEMPERATURE
; How to Convert Celsius to Fahrenheit
; F = 9/5 * C + 32
; C = 5/9 * (F - 32)

; Example: convert 15 °C to °F:
; 15°C = 15 * 9/5 + 32 = 59 °F

; PRESSURE
; How to convert inches to mbar:

; To convert inches of mercury to millibars, multiply the inches value by 33.8637526
; To convert millibars to inches of mercury, multiply the millibar value by 0.0295301

; Example: convert 30.15 in to mb:
; 30.15 in = 30.15 * 33.8637526 = 1020.99 ~ 1021 mb


[.SuperParent]
Measure=WebParser
URL=#URLSite#
;#URLSite#
;file://#@#JSONen-US.txt
DecodeCharacterReference=1
UpdateRate=#UpdateRate#
LogSubstringErrors=0
RegExp=(?siU).*"WeatherStore":(.*)"photos":.*
StringIndex=1
FinishAction=[!EnableMeasureGroup Parents]
; Debug=2
; Debug2File=#@#JSON#Language#.txt

; =========================================
; Location information
; =========================================

; Returns: Region/Country, Location Name, Latitude, Logitude, TimeOffset, Pressure, Condition Icon, ConditionText, DayText, NightText (if available), Temp Now, Temp High, Temp Low, FeelsLike, ObsTimeStamp, Humidity, PrecipPercent, UVText, UVIndex, Visibility, WindDirection, WindDirectionCode, WindSpeed, Sunrise, Sunset, MoonPhase 

[.CurrentParent]
Measure=WebParser
Group=Parents
URL=[.SuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)#Current#
FinishAction=[!EnableMeasureGroup Times0][!UpdateMeasureGroup Times0]

[.LocationCountry]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=1

[.LocationName]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=2

[.LocationLatitude]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=3

[.LocationLongitude]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=4

[.LocationTimeZone]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=5
OnChangeAction=[!EnableMeasure .LocationTimeZoneAbbreviation][!UpdateMeasure .LocationTimeZoneAbbreviation]

[.LocationTimeZoneAbbreviation]
Measure=Calc
Formula=[.LocationTimeZone]/3600
Disabled=1
DynamicVariables=1
Substitute=#TimeZones#

; =============================================
; Current Conditions as of the Observation Time
; =============================================

[.CurrentPressureF]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=6
RegExpSubstitute=1
Substitute="^(..\...).*$":"\1"
OnChangeAction=[!EnableMeasure .CurrentPressureC][!UpdateMeasure .CurrentPressureC]

[.CurrentPressureC]
Measure=Calc
Formula=([.CurrentPressureF] * 33.8637526)
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,4}\..).*$":"\1"

[.CurrentIcon]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=7

[.CurrentObservationDate]
Measure=Time
Group=Times0
Disabled=1
TimeStamp=[.CurrentObservationTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#
FormatLocale=#Language#

[.CurrentObservationTime]
Measure=Time
Group=Times0
Disabled=1
TimeStamp=[.CurrentObservationTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"

[.CurrentConditions]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=8

[.CurrentNightNarrative]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=9

[.CurrentDayNarrative]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=10

[.CurrentTemperatureF]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=11
OnChangeAction=[!EnableMeasure .CurrentTemperatureC][!UpdateMeasure .CurrentTemperatureC]

[.CurrentTemperatureC]
Measure=Calc
Formula=([.CurrentTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.CurrentTemperatureHighF]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=12
OnChangeAction=[!EnableMeasure .CurrentTemperatureHighC][!UpdateMeasure .CurrentTemperatureHighC]

[.CurrentTemperatureHighC]
Measure=Calc
Formula=([.CurrentTemperatureHighF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.CurrentTemperatureLowF]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=13
OnChangeAction=[!EnableMeasure .CurrentTemperatureLowC][!UpdateMeasure .CurrentTemperatureLowC]

[.CurrentTemperatureLowC]
Measure=Calc
Formula=([.CurrentTemperatureLowF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.CurrentFeelsLikeF]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=14
OnChangeAction=[!EnableMeasure .CurrentFeelsLikeC][!UpdateMeasure .CurrentFeelsLikeC]

[.CurrentFeelsLikeC]
Measure=Calc
Formula=([.CurrentFeelsLikeF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.CurrentObservationTimeStamp]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=15

[.CurrentHumidity]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=16
MinValue=0
MaxValue=100

[.CurrentPrecipitationLast24Hours]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=17

[.CurrentUVIndex]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=19
MinValue=0
MaxValue=10

[.CurrentUVDescription]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=18

[.CurrentVisibilityDistanceF]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=20
RegExpSubstitute=1
Substitute="^(\d{0,2}\..).*$":"\1"
OnChangeAction=[!EnableMeasure .CurrentVisibilityDistanceC][!UpdateMeasure .CurrentVisibilityDistanceC]

[.CurrentVisibilityDistanceC]
Measure=Calc
Formula=([.CurrentVisibilityDistanceF] * 1.609344)
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{0,2}\..).*$":"\1"

[.CurrentWindSpeedF]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=23
OnChangeAction=[!EnableMeasure .CurrentWindSpeedC][!UpdateMeasure .CurrentWindSpeedC]

[.CurrentWindSpeedC]
Measure=Calc
Formula=([.CurrentWindSpeedF] * 1.609344)
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{0,3})\..*$":"\1"

[.CurrentWindDirectionCompass]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=22

[.CurrentWindDirectionDegrees]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=21
MinValue=0
MaxValue=360

[.CurrentSunriseTimeStamp]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=24

[.CurrentSunriseTime]
Measure=Time
Group=Times0
Disabled=1
TimeStamp=[.CurrentSunriseTimeStamp]
DynamicVariables=1
Format=#TimeFormat#
FormatLocale=#Language#
RegExpSubstitute=1
Substitute="(^.*$)":"\1","AM":"am","PM":"pm"

[.CurrentSunSetTimeStamp]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=25

[.CurrentSunsetTime]
Measure=Time
Group=Times0
Disabled=1
TimeStamp=[.CurrentSunsetTimeStamp]
DynamicVariables=1
Format=#TimeFormat#
FormatLocale=#Language#
RegExpSubstitute=1
Substitute="(^.*$)":"\1","AM":"am","PM":"pm"

[.CurrentMoonPhase]
Measure=WebParser
URL=[.CurrentParent]
StringIndex=26

; Substitute numbers with descriptions for use in string meters
Substitute="0":"New Moon","1":"Waxing Crescent","2":"First Quarter","3":"Waxing Gibbous","4":"Full Moon","5":"Waning Gibbous","6":"Third Quarter","7":"Waning Crescent"

; Substitute numbers with abbreviation image names
;Substitute="0":"N","1":"WXC","2":"FQ","3":"WXG","4":"F","5":"WNG","6":"LQ","7":"WNC"

[.CurrentDayNight]
Measure=Calc
Group=Times0
Formula=[.CurrentObservationTime:]>=[.CurrentSunsetTime:]
IfCondition=([.CurrentObservationTime:]>=[.CurrentSunsetTime:])
IfTrueAction=[!SetVariable CurrentTime Night]
IfFalseAction=[!SetVariable CurrentTime Day]
Disabled=1

; ========================================
; Forecasts for today and following 10 days
; ========================================

; Returns: ConditionIcon, ConditionText, DayText, NightText, High, Low, TimeStamp, Humidity, PrecipPercent
[.ForecastTodayParent]
Measure=WebParser
Group=Parents
URL=[.SuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU).*"daily"#Day##Day##Day##Day##Day##Day##Day##Day##Day##Day#
LogSubstringErrors=0
FinishAction=[!EnableMeasureGroup Times10][!UpdateMeasureGroup Times10]

; ========================================
; Forecasts for today
; ========================================

[.ForecastTodayDayIcon]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=1

[.ForecastTodayDayConditions]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=2

[.ForecastTodayDayNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=3

[.ForecastTodayNightNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=4

[.ForecastTodayDayHighTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=5
OnChangeAction=[!EnableMeasure .ForecastTodayDayHighTemperatureC][!UpdateMeasure .ForecastTodayDayHighTemperatureC]

[.ForecastTodayDayHighTemperatureC]
Measure=Calc
Formula=([.ForecastTodayDayHighTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastTodayDayLowTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=6
OnChangeAction=[!EnableMeasure .ForecastTodayDayLowTemperatureC][!UpdateMeasure .ForecastTodayDayLowTemperatureC]

[.ForecastTodayDayLowTemperatureC]
Measure=Calc
Formula=([.ForecastTodayDayLowTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastTodayTimeStamp]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=7

[.ForecastTodayObservationTime]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastTodayTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"

[.ForecastTodayObservationDate]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastTodayTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#
FormatLocale=#Language#

[.ForecastTodayObservationDayName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastTodayTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%A
FormatLocale=#Language#

[.ForecastTodayObservationDayNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastTodayTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%a
FormatLocale=#Language#

[.ForecastTodayObservationMonthName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastTodayTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%B
FormatLocale=#Language#

[.ForecastTodayObservationMonthNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastTodayTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%b
FormatLocale=#Language#

[.ForecastTodayObservationDayOfMonth]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastTodayTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%e
FormatLocale=#Language#

[.ForecastTodayDayHumidity]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=8
MinValue=0
MaxValue=100

[.ForecastTodayDayPrecipitationPercent]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=9

; ========================================
; Forecasts for Day 2
; ========================================

[.ForecastDay2Icon]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=10

[.ForecastDay2Conditions]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=11

[.ForecastDay2DayNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=12

[.ForecastDay2NightNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=13

[.ForecastDay2HighTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=14
OnChangeAction=[!EnableMeasure .ForecastDay2HighTemperatureC][!UpdateMeasure .ForecastDay2HighTemperatureC]

[.ForecastDay2HighTemperatureC]
Measure=Calc
Formula=([.ForecastDay2HighTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay2LowTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=15
OnChangeAction=[!EnableMeasure .ForecastDay2LowTemperatureC][!UpdateMeasure .ForecastDay2LowTemperatureC]

[.ForecastDay2LowTemperatureC]
Measure=Calc
Formula=([.ForecastDay2LowTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay2TimeStamp]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=16

[.ForecastDay2ObservationTime]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay2TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"

[.ForecastDay2ObservationDate]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay2TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#
FormatLocale=#Language#

[.ForecastDay2ObservationDayName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay2TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%A
FormatLocale=#Language#

[.ForecastDay2ObservationDayNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay2TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%a
FormatLocale=#Language#

[.ForecastDay2ObservationMonthName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay2TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%B
FormatLocale=#Language#

[.ForecastDay2ObservationMonthNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay2TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%b
FormatLocale=#Language#

[.ForecastDay2ObservationDayOfMonth]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay2TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%e
FormatLocale=#Language#

[.ForecastDay2Humidity]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=17
MinValue=0
MaxValue=100

[.ForecastDay2PrecipitationPercent]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=18

; ========================================
; Forecasts for Day 3
; ========================================

[.ForecastDay3Icon]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=19

[.ForecastDay3Conditions]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=20

[.ForecastDay3DayNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=21

[.ForecastDay3NightNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=22

[.ForecastDay3HighTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=23
OnChangeAction=[!EnableMeasure .ForecastDay3HighTemperatureC][!UpdateMeasure .ForecastDay3HighTemperatureC]

[.ForecastDay3HighTemperatureC]
Measure=Calc
Formula=([.ForecastDay3HighTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay3LowTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=24
OnChangeAction=[!EnableMeasure .ForecastDay3LowTemperatureC][!UpdateMeasure .ForecastDay3LowTemperatureC]

[.ForecastDay3LowTemperatureC]
Measure=Calc
Formula=([.ForecastDay3LowTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay3TimeStamp]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=25

[.ForecastDay3ObservationTime]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay3TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"

[.ForecastDay3ObservationDate]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay3TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#
FormatLocale=#Language#

[.ForecastDay3ObservationDayName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay3TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%A
FormatLocale=#Language#

[.ForecastDay3ObservationDayNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay3TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%a
FormatLocale=#Language#

[.ForecastDay3ObservationMonthName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay3TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%B
FormatLocale=#Language#

[.ForecastDay3ObservationMonthNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay3TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%b
FormatLocale=#Language#

[.ForecastDay3ObservationDayOfMonth]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay3TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%e
FormatLocale=#Language#

[.ForecastDay3Humidity]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=26
MinValue=0
MaxValue=100

[.ForecastDay3PrecipitationPercent]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=27

; ========================================
; Forecasts for Day 4
; ========================================

[.ForecastDay4Icon]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=28

[.ForecastDay4Conditions]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=29

[.ForecastDay4DayNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=30

[.ForecastDay4NightNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=31

[.ForecastDay4HighTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=32
OnChangeAction=[!EnableMeasure .ForecastDay4HighTemperatureC][!UpdateMeasure .ForecastDay4HighTemperatureC]

[.ForecastDay4HighTemperatureC]
Measure=Calc
Formula=([.ForecastDay4HighTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay4LowTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=33
OnChangeAction=[!EnableMeasure .ForecastDay4LowTemperatureC][!UpdateMeasure .ForecastDay4LowTemperatureC]

[.ForecastDay4LowTemperatureC]
Measure=Calc
Formula=([.ForecastDay4LowTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay4TimeStamp]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=34

[.ForecastDay4ObservationTime]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay4TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"

[.ForecastDay4ObservationDate]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay4TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#
FormatLocale=#Language#

[.ForecastDay4ObservationDayName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay4TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%A
FormatLocale=#Language#

[.ForecastDay4ObservationDayNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay4TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%a
FormatLocale=#Language#

[.ForecastDay4ObservationMonthName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay4TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%B
FormatLocale=#Language#

[.ForecastDay4ObservationMonthNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay4TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%b
FormatLocale=#Language#

[.ForecastDay4ObservationDayOfMonth]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay4TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%e
FormatLocale=#Language#

[.ForecastDay4Humidity]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=35
MinValue=0
MaxValue=100

[.ForecastDay4PrecipitationPercent]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=36

; ========================================
; Forecasts for Day 5
; ========================================

[.ForecastDay5Icon]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=37

[.ForecastDay5Conditions]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=38

[.ForecastDay5DayNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=39

[.ForecastDay5NightNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=40

[.ForecastDay5HighTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=41
OnChangeAction=[!EnableMeasure .ForecastDay5HighTemperatureC][!UpdateMeasure .ForecastDay5HighTemperatureC]

[.ForecastDay5HighTemperatureC]
Measure=Calc
Formula=([.ForecastDay5HighTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay5LowTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=42
OnChangeAction=[!EnableMeasure .ForecastDay5LowTemperatureC][!UpdateMeasure .ForecastDay5LowTemperatureC]

[.ForecastDay5LowTemperatureC]
Measure=Calc
Formula=([.ForecastDay5LowTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay5TimeStamp]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=43

[.ForecastDay5ObservationTime]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay5TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"

[.ForecastDay5ObservationDate]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay5TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#
FormatLocale=#Language#

[.ForecastDay5ObservationDayName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay5TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%A
FormatLocale=#Language#

[.ForecastDay5ObservationDayNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay5TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%a
FormatLocale=#Language#

[.ForecastDay5ObservationMonthName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay5TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%B
FormatLocale=#Language#

[.ForecastDay5ObservationMonthNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay5TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%b
FormatLocale=#Language#

[.ForecastDay5ObservationDayOfMonth]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay5TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%e
FormatLocale=#Language#

[.ForecastDay5Humidity]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=44
MinValue=0
MaxValue=100

[.ForecastDay5PrecipitationPercent]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=45

; ========================================
; Forecasts for Day 6
; ========================================

[.ForecastDay6Icon]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=46

[.ForecastDay6Conditions]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=47

[.ForecastDay6DayNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=48

[.ForecastDay6NightNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=49

[.ForecastDay6HighTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=50
OnChangeAction=[!EnableMeasure .ForecastDay6HighTemperatureC][!UpdateMeasure .ForecastDay6HighTemperatureC]

[.ForecastDay6HighTemperatureC]
Measure=Calc
Formula=([.ForecastDay6HighTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay6LowTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=51
OnChangeAction=[!EnableMeasure .ForecastDay6LowTemperatureC][!UpdateMeasure .ForecastDay6LowTemperatureC]

[.ForecastDay6LowTemperatureC]
Measure=Calc
Formula=([.ForecastDay6LowTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay6TimeStamp]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=52

[.ForecastDay6ObservationTime]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay6TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"

[.ForecastDay6ObservationDate]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay6TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#
FormatLocale=#Language#

[.ForecastDay6ObservationDayName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay6TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%A
FormatLocale=#Language#

[.ForecastDay6ObservationDayNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay6TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%a
FormatLocale=#Language#

[.ForecastDay6ObservationMonthName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay6TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%B
FormatLocale=#Language#

[.ForecastDay6ObservationMonthNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay6TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%b
FormatLocale=#Language#

[.ForecastDay6ObservationDayOfMonth]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay6TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%e
FormatLocale=#Language#

[.ForecastDay6Humidity]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=53
MinValue=0
MaxValue=100

[.ForecastDay6PrecipitationPercent]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=54

; ========================================
; Forecasts for Day 7
; ========================================

[.ForecastDay7Icon]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=55

[.ForecastDay7Conditions]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=56

[.ForecastDay7DayNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=57

[.ForecastDay7NightNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=58

[.ForecastDay7HighTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=59
OnChangeAction=[!EnableMeasure .ForecastDay7HighTemperatureC][!UpdateMeasure .ForecastDay7HighTemperatureC]

[.ForecastDay7HighTemperatureC]
Measure=Calc
Formula=([.ForecastDay7HighTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay7LowTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=60
OnChangeAction=[!EnableMeasure .ForecastDay7LowTemperatureC][!UpdateMeasure .ForecastDay7LowTemperatureC]

[.ForecastDay7LowTemperatureC]
Measure=Calc
Formula=([.ForecastDay7LowTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay7TimeStamp]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=61

[.ForecastDay7ObservationTime]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay7TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"

[.ForecastDay7ObservationDate]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay7TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#
FormatLocale=#Language#

[.ForecastDay7ObservationDayName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay7TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%A
FormatLocale=#Language#

[.ForecastDay7ObservationDayNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay7TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%a
FormatLocale=#Language#

[.ForecastDay7ObservationMonthName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay7TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%B
FormatLocale=#Language#

[.ForecastDay7ObservationMonthNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay7TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%b
FormatLocale=#Language#

[.ForecastDay7ObservationDayOfMonth]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay7TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%e
FormatLocale=#Language#

[.ForecastDay7Humidity]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=62
MinValue=0
MaxValue=100

[.ForecastDay7PrecipitationPercent]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=63

; ========================================
; Forecasts for Day 8
; ========================================

[.ForecastDay8Icon]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=64

[.ForecastDay8Conditions]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=65

[.ForecastDay8DayNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=66

[.ForecastDay8NightNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=67

[.ForecastDay8HighTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=68
OnChangeAction=[!EnableMeasure .ForecastDay8HighTemperatureC][!UpdateMeasure .ForecastDay8HighTemperatureC]

[.ForecastDay8HighTemperatureC]
Measure=Calc
Formula=([.ForecastDay8HighTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay8LowTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=69
OnChangeAction=[!EnableMeasure .ForecastDay8LowTemperatureC][!UpdateMeasure .ForecastDay8LowTemperatureC]

[.ForecastDay8LowTemperatureC]
Measure=Calc
Formula=([.ForecastDay8LowTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay8TimeStamp]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=70

[.ForecastDay8ObservationTime]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay8TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"

[.ForecastDay8ObservationDate]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay8TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#
FormatLocale=#Language#

[.ForecastDay8ObservationDayName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay8TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%A
FormatLocale=#Language#

[.ForecastDay8ObservationDayNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay8TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%a
FormatLocale=#Language#

[.ForecastDay8ObservationMonthName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay8TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%B
FormatLocale=#Language#

[.ForecastDay8ObservationMonthNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay8TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%b
FormatLocale=#Language#

[.ForecastDay8ObservationDayOfMonth]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay8TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%e
FormatLocale=#Language#

[.ForecastDay8Humidity]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=71
MinValue=0
MaxValue=100

[.ForecastDay8PrecipitationPercent]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=72

; ========================================
; Forecasts for Day 9
; ========================================

[.ForecastDay9Icon]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=73

[.ForecastDay9Conditions]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=74

[.ForecastDay9DayNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=75

[.ForecastDay9NightNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=76

[.ForecastDay9HighTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=77
OnChangeAction=[!EnableMeasure .ForecastDay9HighTemperatureC][!UpdateMeasure .ForecastDay9HighTemperatureC]

[.ForecastDay9HighTemperatureC]
Measure=Calc
Formula=([.ForecastDay9HighTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay9LowTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=78
OnChangeAction=[!EnableMeasure .ForecastDay9LowTemperatureC][!UpdateMeasure .ForecastDay9LowTemperatureC]

[.ForecastDay9LowTemperatureC]
Measure=Calc
Formula=([.ForecastDay9LowTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay9TimeStamp]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=79

[.ForecastDay9ObservationTime]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay9TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"

[.ForecastDay9ObservationDate]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay9TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#
FormatLocale=#Language#

[.ForecastDay9ObservationDayName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay9TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%A
FormatLocale=#Language#

[.ForecastDay9ObservationDayNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay9TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%a
FormatLocale=#Language#

[.ForecastDay9ObservationMonthName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay9TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%B
FormatLocale=#Language#

[.ForecastDay9ObservationMonthNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay9TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%b
FormatLocale=#Language#

[.ForecastDay9ObservationDayOfMonth]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay9TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%e
FormatLocale=#Language#

[.ForecastDay9Humidity]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=80
MinValue=0
MaxValue=100

[.ForecastDay9PrecipitationPercent]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=81

; ========================================
; Forecasts for Day 10
; ========================================

[.ForecastDay10Icon]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=82

[.ForecastDay10Conditions]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=83

[.ForecastDay10DayNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=84

[.ForecastDay10NightNarrative]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=85

[.ForecastDay10HighTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=86
OnChangeAction=[!EnableMeasure .ForecastDay10HighTemperatureC][!UpdateMeasure .ForecastDay10HighTemperatureC]

[.ForecastDay10HighTemperatureC]
Measure=Calc
Formula=([.ForecastDay10HighTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay10LowTemperatureF]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=87
OnChangeAction=[!EnableMeasure .ForecastDay10LowTemperatureC][!UpdateMeasure .ForecastDay10LowTemperatureC]

[.ForecastDay10LowTemperatureC]
Measure=Calc
Formula=([.ForecastDay10LowTemperatureF] - 32) * 5/9
Disabled=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="^(\d{1,2}\..).*$":"\1"

[.ForecastDay10TimeStamp]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=88

[.ForecastDay10ObservationTime]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay10TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
FormatLocale=#Language#
Substitute="AM":"am","PM":"pm"

[.ForecastDay10ObservationDate]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay10TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#
FormatLocale=#Language#

[.ForecastDay10ObservationDayName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay10TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%A
FormatLocale=#Language#

[.ForecastDay10ObservationDayNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay10TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%a
FormatLocale=#Language#

[.ForecastDay10ObservationMonthName]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay10TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%B
FormatLocale=#Language#

[.ForecastDay10ObservationMonthNameShort]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay10TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%b
FormatLocale=#Language#

[.ForecastDay10ObservationDayOfMonth]
Measure=Time
Group=Times10
Disabled=1
TimeStamp=[.ForecastDay10TimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=%e
FormatLocale=#Language#

[.ForecastDay10Humidity]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=89
MinValue=0
MaxValue=100

[.ForecastDay10PrecipitationPercent]
Measure=WebParser
URL=[.ForecastTodayParent]
StringIndex=90

