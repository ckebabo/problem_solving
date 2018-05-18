import sys, os
from getpass import getpass

import mechanize

br = mechanize.Browser()
br.set_handle_robots(False)
br.set_handle_refresh(False)

filename = sys.argv[1]
problem, _ = os.path.splitext(filename)

url = 'https://algospot.com/accounts/login/?next=/judge/problem/submit/' + problem
response = br.open(url)
br.form = br.forms()[2]

br.form.find_control('username').value = raw_input('username : ')
br.form.find_control('password').value = getpass('password : ')
response = br.submit()

br.form = br.forms()[2]
br.form.find_control('language').value = ['cpp']
br.form.find_control('source').value = open(filename, mode='r').read()
response = br.submit()

