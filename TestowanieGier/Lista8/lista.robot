*** Settings ***
Library  SeleniumLibrary

*** Variables ***
${DRIVER}   C:/Users/kasia/OneDrive/Pulpit/aaa/chromedriver.exe
${BROWSER}  Chrome
${URL}      file:///C:/Users/kasia/OneDrive/Pulpit/aaa/page/index.html

*** Test Cases ***
Zadanie1
    Create Webdriver    ${BROWSER}    executable_path=${DRIVER}
    Go To               ${URL}
    ${url1}             Get Location
    Click Element       id:new_window_button
    ${url2}             Get Location
    Should Be Equal     ${url1}  ${url2}
    Close Browser

Zadanie2
    Create Webdriver    ${BROWSER}    executable_path=${DRIVER}
    Go To               ${URL}
    Click Element       xpath: //*[contains(text(), "Contact")]
    Wait Until Page Contains Element    id:contact_form
    ${var}              Get Text    id:name
    Should Be Equal     ${var}   ${EMPTY}
    ${var}              Get Text    id:surname
    Should Be Equal     ${var}   ${EMPTY}
    ${var}              Get Text    id:email
    Should Be Equal     ${var}   ${EMPTY}
    ${var}              Get Text    id:message
    Should Be Equal     ${var}   ${EMPTY}
    Input Text          id:name  Jan
    Input Text          id:surname  Kowalski
    Input Text          id:email  jan.kowalski@gmail.com
    Input Text          id:message  Krótka Wiadomość
    Click Element       id:country
    Click Element       xpath: //*[contains(text(), "Poland")]
    Click Button        xpath: //input[@type='submit']
    Alert Should Be present     text=Are you sure?  action=ACCEPT
    Close Browser

Zadanie3
    Create Webdriver    ${BROWSER}    executable_path=${DRIVER}
    Go To               ${URL}
    Click Element       xpath: //*[contains(text(), "Gallery")]
    ${vars}             Get WebElements  xpath: //*[@class='gallery']
    ${length}           Get Length  ${vars}
    Should Be Equal     ${length}  ${11}
    FOR   ${var}  IN  ${vars}
        ${var}              Get Element Attribute  ${var}  src
        Log To Console      ${var}
    END
    Close Browser

Zadanie4
    Create Webdriver    ${BROWSER}    executable_path=${DRIVER}
    Go To               ${URL}
    ${vars}             Get WebElements  xpath: //*[@class='img_link']
    ${length}           Get Length  ${vars}
    Should Be Equal     ${length}  ${4}
    FOR  ${var}  IN  ${vars}
        ${var}              Get Element Attribute  ${var}  alt
        Go To               https://pl.pinterest.com/
        ${title}            Get title
        Should Contain      ${title}  ${var}
        Go Back
    END
    Close Browser