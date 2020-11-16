#!/usr/bin/node

const request = require('request');
const api_url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;
request(api_url, (error, response, body) => {
  if (error) {
    return;
  }
  const request_response = JSON.parse(body);
  const name = {};
  request_response.characters.forEach(people_api => {
    request(people_api, (error, response, body) => {
      if (error) {
        return;
      }
      const character = JSON.parse(body);
      console.log(character.name);
    });
  });
});
