#!/bin/sh

# Generate PDF documentation from Asciidoc documents.
#
# Dependencies
#   - Asciidoctorj or Asciidoctor- asciidoc processor
#       sdk install asciidoctorj
#   - Asciidoctor-pdf - used to generate file in PDF format
#       sudo gem install asciidoctor-pdf --pre
#   - plantuml - (optional) used if document contains Graphvis or Plantuml diagrams
#       sudo apt-get install graphviz
#  - Microsoft Core Fonts - (optional)
#       sudo apt-get install ttf-mscorefonts-installer

error() {
    echo $1
    exit 1
}

scriptDir=$(cd "$(dirname "$0")"; pwd)

sampleDir=$scriptDir
buildDir=$scriptDir/build

test -d "$sampleDir" || error "Sample dir '$sampleDir' does not exist. Usage: $0 sample-base"

mkdir -p $buildDir
mkdir -p $buildDir/images
cp $sampleDir/images/* $buildDir/images/

# Copy source images to build folder.
# graphviz puts generated images to home directory (where adoc file is existed)
#                           or to directory defined by variable :imagesdir:.
#
# In this case variable :imagesdir: can be set as global variable (in adoc files):
#:imagesdir: {imagesdir-build}
#
# All static images (png, jpg, etc... ) should be mentioned with directory 'images':
# image::images/image.png[]

asciidoctorj --backend pdf \
     --attribute version=0.0.1 \
     --attribute imagesdir-build=$buildDir \
     --base-dir $sampleDir \
     --require asciidoctor-diagram \
     --destination-dir $sampleDir \
     --out-file esp8266.pdf \
     $sampleDir/esp8266.adoc

rm -rf $buildDir
