#!/bin/bash

device_id="PHOTON_DEVICE_ID"
access_token="ACCESS_TOKEN"

curl https://api.particle.io/v1/devices/$device_id/SetThreshold -d access_token=$access_token -d param=$1