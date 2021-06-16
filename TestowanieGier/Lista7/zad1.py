import time
import requests
import bs4
from selenium import webdriver
from selenium.webdriver.support.ui import Select
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains


def task1(slow=1):
    print("Python1")
    driver = webdriver.Chrome('C:/Users/kasia/OneDrive/Pulpit/aaa/chromedriver.exe') 

    driver.get("file:///C:/Users/kasia/OneDrive/Pulpit/aaa/page/index.html")
    time.sleep(slow * 0.5)
    driver.find_elements_by_tag_name('a')[2].click()
    time.sleep(slow * 0.5)
    driver.find_element_by_id('name').send_keys("Anna")
    time.sleep(slow * 0.5)
    driver.find_element_by_id('surname').send_keys("Wesołowska")
    time.sleep(slow * 0.5)
    driver.find_element_by_id('email').send_keys("anna.wesolowska@gmail.com")
    time.sleep(slow * 0.5)
    select = Select(driver.find_element_by_id('country'))
    time.sleep(slow * 0.5)
    select.select_by_visible_text('Poland')
    time.sleep(slow * 0.5)
    driver.find_element_by_id('message').send_keys("Wiadomosc")
    time.sleep(slow * 0.5)
    driver.save_screenshot("screen1.png")
    time.sleep(slow * 0.5)
    driver.find_element_by_xpath(".//*[@type='submit']").click()
    time.sleep(slow * 0.5)
    alert = driver.switch_to.alert
    alert.accept()
    time.sleep(slow * 2)



task1()