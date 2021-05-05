package com.company;

import java.io.*;

import org.junit.jupiter.api.extension.ExtensionContext;
import org.junit.jupiter.api.extension.ParameterContext;
import org.junit.jupiter.api.extension.ParameterResolutionException;
import org.junit.jupiter.api.extension.ParameterResolver;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.security.cert.Extension;
import java.util.Scanner;

import static java.lang.annotation.RetentionPolicy.*;

public class FileExtension implements ParameterResolver
{
    @Retention(RetentionPolicy.RUNTIME)
    public @interface File{
            String path();
    }
    @Override
    public boolean supportsParameter(ParameterContext parameterContext, ExtensionContext extensionContext) throws ParameterResolutionException {
        return parameterContext.getParameter().getType()==String.class;
    }

    @Override
    public Object resolveParameter(ParameterContext parameterContext, ExtensionContext extensionContext) throws ParameterResolutionException {
        File file = parameterContext.getParameter().getAnnotation(File.class);
        String filepath = file.path();
        java.io.File realfile = new java.io.File(filepath);
        Scanner sc=null;
        try {
            sc = new Scanner(realfile);

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        StringBuilder res= new StringBuilder();
        while (sc.hasNext())
        {
            res.append(sc.nextLine());
        }
        sc.close();
        return res.toString();
    }
}
