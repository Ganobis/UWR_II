*** Settings ***
Library  SeleniumLibrary
Library  Modul.py

*** Variables ***
${DRIVER}   C:/Users/kasia/OneDrive/Pulpit/aaa/chromedriver.exe
${BROWSER}  Chrome
${URL}      file:///C:/Users/kasia/OneDrive/Pulpit/aaa/page/index.html

*** Test Cases ***
Test1
    Create Webdriver    ${BROWSER}    executable_path=${DRIVER}
    Go To               ${URL}
    ${var1}             Get title
    Should Be Equal To Or  ${var1}  home  Home
    Close Browser

Test2
    Create Webdriver    ${BROWSER}    executable_path=${DRIVER}
    Go To               ${URL}
    Click Element       xpath: //*[contains(text(), "Contact")]
    ${var1}             Get title
    Should Be Equal To Or  ${var1}  Contact  contact
    Close Browser