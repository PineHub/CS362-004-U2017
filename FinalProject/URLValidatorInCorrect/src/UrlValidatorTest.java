/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;
import java.util.Random;




/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("mailto:bingo@abc.com"));
	    
	   
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   
   public void testIsValid()
   {
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   Random rand = new Random(); 
	   int randomA, randomB, randomC, randomD, randomE, randomF, randomG, randomH;
	   String[] validStart = {"http://", "ftp://", "https://", "mailto://", "file://", "irc://", "data://"};
	   String[] validSecond = {"www.", ""};
	   String[] validDomainPart = {"photos.", ""};
	   String[] validDomain = {"google."};
	   String[] validTld = {"com", "org", "net", "edu", "info"};
	   String[] validRoutes = {"/route", ""};
	   String[] validPort = {":8000", ""};
	   String[] validQuery = {"?a=b", ""};
	   for(int i = 0;i<10000;i++)
	   {
	   randomA = rand.nextInt(7);
	   randomB = rand.nextInt(2);
	   randomC = rand.nextInt(2);
	   randomD = 0;
	   randomE  = rand.nextInt(5);
	   randomF = rand.nextInt(2);
	   randomG = rand.nextInt(2);
	   randomH = rand.nextInt(2);
	    
	   String testStr = "" + 
	   validStart[randomA] +
	   "" +
	   validSecond[randomB] +
	   validDomainPart[randomC] +
	   validDomain[randomD] +
	   validTld[randomE] +
	   validRoutes[randomF] +
	   validPort[randomG] +
	   validQuery[randomH];
	    
	   System.out.println(testStr);
	   System.out.println(urlVal.isValid(testStr));
	   }
	   
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
