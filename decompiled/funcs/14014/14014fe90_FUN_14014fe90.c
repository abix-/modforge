// Address: 0x14014fe90
// Ghidra name: FUN_14014fe90
// ============ 0x14014fe90 FUN_14014fe90 (size=193) ============


ulonglong FUN_14014fe90(undefined8 param_1,undefined4 param_2,undefined4 param_3,char *param_4,

                       undefined8 param_5)



{

  byte bVar1;

  int iVar2;

  ulonglong uVar3;

  undefined8 local_48 [7];

  

  iVar2 = strcmp(param_4,"%s");

  if (iVar2 == 0) {

    uVar3 = FUN_14014ff60(param_1,param_2,param_3,param_5);

    return uVar3;

  }

  local_48[0] = 0;

  uVar3 = FUN_14012f790(local_48,param_4,&param_5);

  if ((int)uVar3 == -1) {

    return uVar3 & 0xffffffffffffff00;

  }

  bVar1 = FUN_14014ff60(param_1,param_2,param_3,local_48[0]);

  FUN_1401841e0(local_48[0]);

  return (ulonglong)bVar1;

}




