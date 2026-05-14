// Address: 0x14017d060
// Ghidra name: FUN_14017d060
// ============ 0x14017d060 FUN_14017d060 (size=212) ============


undefined8 FUN_14017d060(undefined4 *param_1)



{

  int iVar1;

  

  if (0xb < param_1[1] - 1) {

    FUN_14012e850("Malformed SDL_DateTime: month out of range [1-12], current: %i");

    return 0;

  }

  iVar1 = FUN_14017d3c0(*param_1);

  if (((int)param_1[2] < 1) || (iVar1 < (int)param_1[2])) {

    FUN_14012e850("Malformed SDL_DateTime: day of month out of range [1-%i], current: %i",iVar1,

                  param_1[1]);

    return 0;

  }

  if (0x17 < (uint)param_1[3]) {

    FUN_14012e850("Malformed SDL_DateTime: hour out of range [0-23], current: %i");

    return 0;

  }

  if ((uint)param_1[4] < 0x3c) {

    if (0x3c < (uint)param_1[5]) {

      FUN_14012e850("Malformed SDL_DateTime: second out of range [0-60], current: %i");

      return 0;

    }

    if ((uint)param_1[6] < 1000000000) {

      return 1;

    }

    FUN_14012e850("Malformed SDL_DateTime: nanosecond out of range [0-999999999], current: %i");

    return 0;

  }

  FUN_14012e850("Malformed SDL_DateTime: minute out of range [0-59], current: %i");

  return 0;

}




