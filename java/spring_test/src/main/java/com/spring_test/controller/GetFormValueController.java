package com.spring_test.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping(value = "/")
public class GetFormValueController {

    @ResponseBody
    @RequestMapping(value = "/form", method = RequestMethod.GET)
    public String getForm() {
        System.out.println("UserName:" + ", PassWord:");
        return "ok 200";
    }
}
