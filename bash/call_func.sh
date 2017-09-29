#!/bin/bash

func1 (){
    echo "Some Function"
}

func2 (){
    func1 > /dev/null
    echo "Func2"
}
func2
