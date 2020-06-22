# Water Level Gauge for Use on Whitewater Rivers

## Abstract

The following report explains how to: build, install, and manage a portable gauge that can be installed on most rivers for the purpose of remotely monitoring volumetric flow. This project is designed to require only a basic understanding of electronics and minimal cost.

## Introduction

In whitewater paddling, the volumetric flow rate of a river is the determining factor of the whitewater conditions. Variation of flow rate changes dynamics within river, creates new waves, hydraulics, exposed rocks, and other river features. This not only alters the enjoyability of paddling the river, but also the safety planning, equipment requirements and skill level.

The development of cellular networks brought the ability to transmit data remotely. This sparked a pivotal time in whitewater kayaking; the ability to centralize real-time river level data. Several organizations, notably American Whitewater, have created an extensive database for most rivers across North America which outlines flow levels, rapids descriptions, accident reports and photos. Many of these rivers are missing volumetric flow data as they rely on hydrologic stations which are out of date, no longer used, or rarely monitored.

any smaller rivers and creeks do pose any risk of flooding surrounding areas, do not have enough energy to merit power generation and do not play a role in agriculture. There is therefor no reason for the government or private organizations monitor its hydrometric data.

## Problem

Installing water level gauges that relay data remotely is an expensive process, and managing the data requires a high degree of technical knowledge. Unless there is an economic incentive for an organization or government to install a gauge, it often does not happen.

With many whitewater rivers and creeks unmonitored, there is no way for whitewater paddlers to remotely know water levels without going to the site. Moving water changes drastically at different levels, and it is often not even possible to accurately judge this visually. For many paddlers, this uncertainty binds them to rivers that are well monitored, or close to their homes.

## Solution

To allow organizations to independently access river stage data, they must have the ability to measure it themselves. This measuring device must meet some requirements:

- Inexpensive
- Easy to Create and Install
- Long-lasting
- Self Sufficient

A measuring device that meets these requirements will remove the barrier that is currently present in the sport of whitewater kayaking.

## Materials

The following section outlines all the hardware involved in the project, accompanied by a description.

### Electronic Components

#### Particle Electron 3G Kit (Americas/Aus)

This kit contains a Particle Electron PCB, Particle SIM Card, Li-Po battery, Taoglas Cellular Antenna, USB cable, Breadboard.

#### MaxBotix XL-MaxSonar-WRCA1

This is an Ultrasonic Range Finder. It functions by emitting sound waves and measuring the time for the signal to return.

### Housing Components

#### Waterproof Plastic Electronic Housing Case

The specific model and dimensions is based on the individual project specifics.

#### Silicone Caulking

Used in the waterproofing process.

#### Silica Gel Desiccant

Removes moisture from air inside case, prolonging device lifetime in humid environments.

## Construction

### Prototyping

Using the electronic components mentioned above, prototyping only involves several simple connections.

#### Connecting the Components

There are four connections that must be made between the Particle Electron and sensor.

| Connection on Sensor        | Connection on Particle Electron |
| --------------------------- | ------------------------------- |
| Analog Feedback Measurement | A0                              |
| On/Off Switch               | D0                              |
| Ground                      | GND                             |
| Power                       | V3.3                            |

### Programming

If using default code and instructions, device will function according to the default specifications in section. Instructions are included on how to change how the device operates. The coding of the gauge is broken into four sections based on the domain that it controls.

#### Particle Build

Particle has an online coding console, called Particle Build, which allows for easy software updating, known as “flashing”.

- [Particle Build](https://console.particle.io/build)

For instruction on how to use Particle, reference the following.

- [Community Tutorials](https://community.particle.io/c/tutorials)
- [Particle Reference Material](https://docs.particle.io/reference/device-os/firmware/electron/)

Use code found in file *gauge.cpp*

#### Particle Cloud Storage

The next process is what allows the data to be sent from the “cloud” to a data storage destination that gives more flexibility of data management.  
The Events Manager is what allows viewing and interaction with all events that were uploaded via the “Particle.publish” function. The name, data, device and “published at” are all viewable.

In this environment, the data is not be graphed or easily manipulated. We need to move it into a more suitable place. This tutorial uses Google sheets due to its ease of use, and its widespread popularity. We must now create a webhook. A webhook is a way for an app to provide other applications with real-time information. A webhook delivers data to other applications as it happens, meaning you get data immediately. This will update the Google Sheets document in real time.

To create a webhook, go to the [integrations](https://console.particle.io/integrations) and click “New Integration”. Click “Webhook”. You will be prompted with a form with several options. Fill in as follows.

| Integration Info | Input              |
| ---------------- | ------------------ |
| Event Name       | Use any choice     |
| Request Type     | POST               |
| Request Form     | Web Form           |
| Device           | Choose only option |
| Form             | waterLevel         |
| Headers          | Yes                |
| Enforce SSL      | Yes                |

Now click “Create Webhook”.

Now that the webhook is active, all measurements will be sent to Google Sheets. At this point, they cannot yet be interpreted properly. This will be resolved in the following section.

#### Google Sheets

Though the data has been sent to Google sheets, it must be properly interpreted, in order to be stored correctly. This is done by creating a google sheets script, written in JavaScript, allowing spreadsheet columns to be recognized, and data formatted. Currently, the data is listed in one large column. Data could be stored by columns of month, day and year modifications to the code.

The script of the Google Sheet document must be edited. Click on “Tools” opening a dropdown menu. Click on “Script Editor”. Paste the code.

After code from the appendix is copied to the Google Sheets script, the ranging data from the device will now input into Google Sheets in one large column.

Code and explanation are found [here](https://gist.github.com/mhawksey/1276293)

#### Presentation

Currently, the data is displayed in a gauge format. Custom ranges and colors can be set, indicating high, normal, and low flows. Each display should be tuned to individual needs. Graphs may be more appropriate for some applications, showing trends over days or weeks. Google Sheets provides comprehensive chart building tools, allowing for a high degree of customization.

For all styles of charts, only the most recent entry should be referenced, reflecting the current water level. This can be done with a simple query in Google Sheets cell. This is found in 9.2 GOOGLE SHEETS QUERY.

### Construction

#### Soldering

After it has been prototyped, programmed and tested. We can create the final gauge by soldering the parts together. This guide will not explain how to transition from a breadboard prototype to a soldered breadboard. Many online resources are available. This step is not crucial but will significantly improve the durability and longevity of the gauge.

#### Power Source

Power Source In order to make this project self-sufficient, it must have a reliable power source. This will depend on the site-specific requirements. Battery power is viable but requires periodic replacement. Wired AC power from a building or outlet is possible but require a source to be near the gauge.

The most viable option is solar power. A small solar panel produces enough energy to power the device. Proper installation requires consideration of geographical location and local environment. It requires a battery to store the power as its non-linear energy production cycles with the sun. The power must be converted to match the energy requirements of the device. This is an area that will be pursued in further revisions of this document.

#### Housing

The final gauge should sit in waterproof plastic box electronics enclosure, large enough to comfortable fit all the components. It should be waterproof, and ideally the same color as its future surroundings, to maintain a low profile. These are readily available to purchase online. A hole should be drilled through the bottom of the enclosure, barely large enough for the sensor to fit through. The sensor should be glued in place, and weather sealed with caulking. The microcontroller should sit at the bottom of the case. A Silica Gel Desiccant should be placed in the box to absorb moisture, extending the life of the electronic components. The solar panel can be installed on of the box, or in a separate location.

### Installation

The device should be installed at a specific height above the river. Under the assumption that there is very little historic river level data, find the oldest record of river stage (no more than 50 years) and add 5cm-10cm.

    installation height = historic maximum level + 5cm

As seen in the range below, the minimum and maximum capabilities of the sensor should be respected.

    minimum rangin boundary < installation height < maximum ranging boundary

The gauge should be installed directly above the water in a calm area, like an eddy or a pool. This will yield the most accurate results. Sensor should be facing straight down, without any obstructions between it and the water. The gauge should be installed as upstream as possible as this will theoretically show the largest change in stage and yield the most accurate results. It should be as attached securely and concealed if possible, reducing the risk of tampering or theft.

Specific tools and methods of installation vary with the specifics of installation location.

## Next Steps

- Migrate to a database in favor of Google Sheets
- Package software for easy implementation
- Expand software to account for more device types
