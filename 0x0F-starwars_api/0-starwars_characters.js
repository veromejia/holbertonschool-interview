#!/usr/bin/node

const request = require('request');
const apiUrl = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;
request(apiUrl, (error, response, body) => {
  if (error) {
    return;
  }
  const requestResponse = JSON.parse(body);
  const name = {};
  requestResponse.characters.forEach(peopleApi => {
    request(peopleApi, (error, response, body) => {
      if (error) {
        return;
      }
      const people = JSON.parse(body);
      name[people.url] = people.name;
      if (Object.keys(name).length === requestResponse.characters.length) {
        requestResponse.characters.forEach(peopleUrl =>
          console.log(name[peopleUrl]));
      }
    });
  });
});
