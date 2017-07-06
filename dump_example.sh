#!/bin/bash


sudo criu dump -D /workspace/temp/criu_images/ -t 3902 --shell-job
