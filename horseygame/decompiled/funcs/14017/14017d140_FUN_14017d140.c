// Address: 0x14017d140
// Ghidra name: FUN_14017d140
// ============ 0x14017d140 FUN_14017d140 (size=273) ============


ulonglong FUN_14017d140(undefined4 *param_1,longlong *param_2)



{

  byte bVar1;

  ulonglong uVar2;

  longlong lVar3;

  longlong lVar4;

  

  bVar1 = 1;

  if (param_1 == (undefined4 *)0x0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403371ac);

    return uVar2;

  }

  if (param_2 == (longlong *)0x0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","ticks");

    return uVar2;

  }

  uVar2 = FUN_14017d060();

  if ((char)uVar2 == '\0') {

    return uVar2;

  }

  lVar3 = FUN_14017cec0(*param_1,param_1[1],param_1[2],0,0);

  *param_2 = lVar3 * 0x15180;

  lVar4 = 0x225c17d03;

  lVar3 = (longlong)(((param_1[3] * 0x3c + param_1[4]) * 0x3c - param_1[8]) + param_1[5]) +

          lVar3 * 0x15180;

  *param_2 = lVar3;

  if ((0x225c17d03 < lVar3) || (lVar4 = -0x225c17d03, lVar3 < -0x225c17d03)) {

    *param_2 = lVar4;

    bVar1 = FUN_14012e850("Date out of range for SDL_Time representation; SDL_Time value clamped");

  }

  *param_2 = (longlong)(int)param_1[6] + *param_2 * 1000000000;

  return (ulonglong)bVar1;

}




