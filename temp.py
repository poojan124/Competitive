if int(country['population']) > p and country['name'].lower() not in names:
    total_count += 1
    names.add(country['name'].lower())