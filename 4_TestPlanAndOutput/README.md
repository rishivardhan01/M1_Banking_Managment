# TEST PLAN and Corresponding Output

## High Level Test Plan
   | Test ID | Description | Exp.i/p | Exp.o/p | Actual o/p | Type Of Test |
   |---------|:------------|:--------|:--------|:-----------|:-------------|
   | H_01 | check if the transaction properly | proper function execution | formatted transaction page | formatted transaction page | Requirement |
   | H_02 | check if the token is displayed properly | program execution | formatted token  page | formatted token page | Requirement |
   | H_03 | check if the token is calling properly | program execution | formatted token page | formatted token page | Requirement |
   | H_04 | check if the account details properly | proper execution | formatted transaction page | formatted transaction  page | Requirement |
   | H_05 | check if the amount is creditted properly | proper execution | formatted transaction page | formatted transaction page | Requirement |
   | H_06 | check if the amount is debitted properly | proper execution | formatted transaction page | formatted transaction page | Requirement |
   | H_07 | check if the token is decalling properly | program execution | formatted token page | formatted token page | Requirement |
   | H_08 | check if the account is validate properly | proper execution | formatted account page | formatted account page | Requirement |
   | H_09 | check if the account details properly | proper execution | formatted account page | formatted account page | Requirement |
   | H_10 | check if the account balance properly | proper execution | formatted account page | formatted account page | Requirement |
   | H_11 | check if the updated account balance properly | proper execution | formatted account page | formatted account page | Requirement |
   | H_12 | check if the account is closed properly | proper execution | formatted account page | formatted account page | Requirement |
   | H_13 | check if the return page displayed properly | program execution | formatted welcome page | formatted welcome page | Requirement |
   
   
   
## Low Level Test Plan
    | Test ID | Description | Exp.i/p | Exp.o/p | Actual o/p | Type Of Test |
    |---------|:------------|:--------|:--------|:-----------|:-------------|
    | L_01 | verify the transactions | amount | name present->avaliable; name absent->not found | name present->avaliable; name absent->not found | Technical |
    | L_02 | verify the tokens | tokens | name present->avaliable; name absent->not found | name present->avaliable; name absent->not found | Technical |
    | L_03 | verify token calling | tokens | name present->avaliable; name absent->not found | name present->avaliable; name absent->not found | Technical |
    | L_04 | verify account | account | account present->avaliable; account absent->not found | account present->avaliable; account absent->not found | Technical |
    | L_05 | verify creditted amount | amount | name present->avaliable; name absent->not found | name present->avaliable; name absent->not found | Technical |
    | L_06 | verify debitted amount | amount | name present->avaliable; name absent->not found | name present->avaliable; name absent->not found | Technical |
    | L_07 | verify token is decalling | token | name present->avaliable; name absent->not found | name present->avaliable; name absent->not found | Technical |
    | L_08 | verify the account | account name | name present->avaliable; name absent->not found | name present->avaliable; name absent->not found | Technical |
    | L_09 | verify account details | account | name present->avaliable; name absent->not found | name present->avaliable; name absent->not found | Technical |
    | L_10 | verify the account balance | account | name present->avaliable; name absent->not found | name present->avaliable; name absent->not found | Technical |
    | L_11 | verify updated account balance | account | name present->avaliable; name absent->not found | name present->avaliable; name absent->not found | Technical |
    | L_12 | verify the closed account | account | name present->avaliable; name absent->not found | name present->avaliable; name absent->not found | Technical |
    | L_13 | verify main page | return | if entries present ->display; if entries absent->not displayed | if entries present ->display; if entries absent->not displayed | Technical |
    