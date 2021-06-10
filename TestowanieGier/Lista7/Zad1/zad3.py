import time
import requests
import bs4
from selenium import webdriver
from selenium.webdriver.support.ui import Select
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains


def task1(slow=1):
    print("Python3")
    driver = webdriver.Chrome('C:/Users/kasia/OneDrive/Pulpit/aaa/chromedriver.exe') 

    driver.get("https://en.wikipedia.org")

    text_box = driver.find_element_by_id("searchInput")
    text_box.send_keys("python")
    time.sleep(0.5)
    text_box.send_keys(Keys.ENTER)
    links = driver.find_elements_by_xpath("//a[@href]")
    proper_links = set()

    for link in links:
        if "Python" in link.get_attribute("href"):
            proper_links.add(link.get_attribute("href"))
    proper_links = list(proper_links)

    for link in proper_links:
        current_window = driver.current_window_handle
        driver.execute_script("window.open('" + link + "');")
        new_window = [window for window in driver.window_handles if window != current_window][0]
        driver.switch_to.window(new_window)

        try:
            title = driver.find_element_by_id("firstHeading")
        except:
            title = None
        if title:
            title = title.text

        first_section = None

        res = requests.get(link)
        res.raise_for_status()
        wiki = bs4.BeautifulSoup(res.text, "html.parser")
        for section in wiki.select('p'):
            if section is not None:
                first_section = section.getText()

        print("Tytuł: ", title)
        print()
        print("Pierwszy akapit: ", first_section)

        driver.close()
        driver.switch_to.window(current_window)
    driver.quit


task1()