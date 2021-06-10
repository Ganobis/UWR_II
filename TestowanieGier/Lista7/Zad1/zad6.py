from time import sleep
import os
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium import webdriver

class SearchPage:
    contact = (By.LINK_TEXT, 'Contact')
    name = (By.ID, 'name')
    surname = (By.ID, 'surname')
    email = (By.ID, 'email')
    country = (By.ID, 'country')
    message = (By.ID, 'message')
    contact_form = (By.ID, 'contact_form')

    def __init__(self, browser):
        print("Python6")
        self.browser = browser

    def load(self):
        self.browser.get("file:///C:/Users/kasia/OneDrive/Pulpit/aaa/page/index.html")

    def navigate_to_contact(self):
        contact = self.browser.find_element(*self.contact)
        contact.click()

    def fill_contact(self, name_, surname_, email_, country_, message_, src_filename_):
        name = self.browser.find_element(*self.name)
        surname = self.browser.find_element(*self.surname)
        email = self.browser.find_element(*self.email)
        country = self.browser.find_element(*self.country)
        message = self.browser.find_element(*self.message)
        contact_form = self.browser.find_element(*self.contact_form)

        name.send_keys(name_)
        surname.send_keys(surname_)
        email.send_keys(email_)
        country.send_keys(country_)
        message.send_keys(message_)

        self.browser.save_screenshot(src_filename_)

        contact_form.submit()
        self.browser.switch_to_alert().accept()
        sleep(1)
        self.browser.quit()

driver = webdriver.Chrome('C:/Users/kasia/OneDrive/Pulpit/aaa/chromedriver.exe') 

sp = SearchPage(driver)
sp.load()
sp.navigate_to_contact()
sp.fill_contact("Anna", "Wesolowska", "annamaria@mail.com", "Poland", "Wiadomosc", "screen6.png")

