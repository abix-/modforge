// Address: 0x1400eda80
// Ghidra name: FUN_1400eda80
// ============ 0x1400eda80 FUN_1400eda80 (size=733) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400eda80(longlong param_1,undefined4 *param_2,undefined4 *param_3,int param_4)



{

  char cVar1;

  byte bVar2;

  undefined4 uVar3;

  char *pcVar4;

  byte *pbVar5;

  uint uVar6;

  uint uVar7;

  

  pcVar4 = *(char **)(param_1 + 0xb8);

  if (*(char **)(param_1 + 0xc0) <= pcVar4) {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400edd49;

    FUN_1400ed820();

    pcVar4 = *(char **)(param_1 + 0xb8);

  }

  cVar1 = *pcVar4;

  pcVar4 = pcVar4 + 1;

  *(char **)(param_1 + 0xb8) = pcVar4;

  if (cVar1 != 'G') {

LAB_1400edd49:

    _DAT_1403f4c40 = "not GIF";

    return 0;

  }

  if (*(char **)(param_1 + 0xc0) <= pcVar4) {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400edd49;

    FUN_1400ed820(param_1);

    pcVar4 = *(char **)(param_1 + 0xb8);

  }

  cVar1 = *pcVar4;

  pcVar4 = pcVar4 + 1;

  *(char **)(param_1 + 0xb8) = pcVar4;

  if (cVar1 != 'I') goto LAB_1400edd49;

  if (*(char **)(param_1 + 0xc0) <= pcVar4) {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400edd49;

    FUN_1400ed820(param_1);

    pcVar4 = *(char **)(param_1 + 0xb8);

  }

  cVar1 = *pcVar4;

  pcVar4 = pcVar4 + 1;

  *(char **)(param_1 + 0xb8) = pcVar4;

  if (cVar1 != 'F') goto LAB_1400edd49;

  if (*(char **)(param_1 + 0xc0) <= pcVar4) {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400edd49;

    FUN_1400ed820(param_1);

    pcVar4 = *(char **)(param_1 + 0xb8);

  }

  cVar1 = *pcVar4;

  pcVar4 = pcVar4 + 1;

  *(char **)(param_1 + 0xb8) = pcVar4;

  if (cVar1 != '8') goto LAB_1400edd49;

  if (*(char **)(param_1 + 0xc0) <= pcVar4) {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400edd49;

    FUN_1400ed820(param_1);

    pcVar4 = *(char **)(param_1 + 0xb8);

  }

  cVar1 = *pcVar4;

  pcVar4 = pcVar4 + 1;

  *(char **)(param_1 + 0xb8) = pcVar4;

  if ((cVar1 - 0x37U & 0xfd) != 0) goto LAB_1400edd49;

  if (*(char **)(param_1 + 0xc0) <= pcVar4) {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400edd49;

    FUN_1400ed820(param_1);

    pcVar4 = *(char **)(param_1 + 0xb8);

  }

  cVar1 = *pcVar4;

  *(char **)(param_1 + 0xb8) = pcVar4 + 1;

  if (cVar1 != 'a') goto LAB_1400edd49;

  _DAT_1403f4c40 = &DAT_14039bcb9;

  uVar3 = FUN_1400e8b80(param_1);

  *param_2 = uVar3;

  uVar3 = FUN_1400e8b80(param_1);

  param_2[1] = uVar3;

  uVar7 = 0;

  pbVar5 = *(byte **)(param_1 + 0xb8);

  if (pbVar5 < *(byte **)(param_1 + 0xc0)) {

    bVar2 = *pbVar5;

    *(byte **)(param_1 + 0xb8) = pbVar5 + 1;

    uVar6 = (uint)bVar2;

  }

  else if (*(int *)(param_1 + 0x30) == 0) {

    uVar6 = 0;

  }

  else {

    FUN_1400ed820(param_1);

    bVar2 = **(byte **)(param_1 + 0xb8);

    *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

    uVar6 = (uint)bVar2;

  }

  param_2[4] = uVar6;

  pbVar5 = *(byte **)(param_1 + 0xb8);

  if (pbVar5 < *(byte **)(param_1 + 0xc0)) {

    uVar6 = (uint)*pbVar5;

    *(byte **)(param_1 + 0xb8) = pbVar5 + 1;

  }

  else if (*(int *)(param_1 + 0x30) == 0) {

    uVar6 = 0;

  }

  else {

    FUN_1400ed820(param_1);

    uVar6 = (uint)**(byte **)(param_1 + 0xb8);

    *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

  }

  param_2[5] = uVar6;

  pbVar5 = *(byte **)(param_1 + 0xb8);

  if (*(byte **)(param_1 + 0xc0) <= pbVar5) {

    if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400edceb;

    FUN_1400ed820(param_1);

    pbVar5 = *(byte **)(param_1 + 0xb8);

  }

  uVar7 = (uint)*pbVar5;

  *(byte **)(param_1 + 0xb8) = pbVar5 + 1;

LAB_1400edceb:

  param_2[6] = uVar7;

  param_2[7] = 0xffffffff;

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = 4;

  }

  if ((param_4 == 0) && ((char)(byte)param_2[4] < '\0')) {

    FUN_1400ee410(param_1,param_2 + 9,2 << ((byte)param_2[4] & 7),0xffffffff);

  }

  return 1;

}




