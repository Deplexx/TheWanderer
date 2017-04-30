#include "p1_hill.h"

#include "GameVars.h"

#include <iostream>

static void branded();
static void attempt_blinded_escape();
static void attempt_escape();

void p1_hill() {
  if(GameVars::feet_bound)
    branded();
  else if(GameVars::blinded)
    attempt_blinded_escape();
  else attempt_escape();
}

//TODO
static void branded() {}

//TODO
static void attempt_blinded_escape() {}

//TODO
static void attempt_escape() {}
