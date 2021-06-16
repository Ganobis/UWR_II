import time
import requests
import os
import urllib.request as tr
import bs4
from selenium import webdriver
from selenium.webdriver.support.ui import Select
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains


def task1(slow=1):
    print("Python2")
    driver = webdriver.Chrome('C:/Users/kasia/OneDrive/Pulpit/aaa/chromedriver.exe') 

    driver.get("file:///C:/Users/kasia/OneDrive/Pulpit/aaa/page/gallery.html")
    time.sleep(slow * 0.5)
    gallery = driver.find_elements_by_class_name("gallery")
    os.makedirs("zadanie2/", exist_ok=True)
    time.sleep(slow * 0.5)
    for image in gallery:
        url = image.get_attribute("src")
        path = os.path.basename(url)
        print(path)
        tr.urlretrieve(url, "zadanie2/" +path)
    time.sleep(slow * 2)
    driver.quit



task1()