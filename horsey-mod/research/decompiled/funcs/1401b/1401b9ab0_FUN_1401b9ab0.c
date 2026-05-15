// Address: 0x1401b9ab0
// Ghidra name: FUN_1401b9ab0
// ============ 0x1401b9ab0 FUN_1401b9ab0 (size=379) ============


undefined8 * FUN_1401b9ab0(longlong param_1,undefined8 param_2)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  undefined8 *puVar4;

  undefined8 *local_res8;

  undefined8 local_res10;

  undefined4 local_38 [2];

  undefined8 local_30;

  undefined4 local_28;

  undefined4 local_24;

  

  local_res8 = (undefined8 *)0x0;

  local_res10 = param_2;

  cVar1 = FUN_1401aaff0(*(undefined8 *)(param_1 + 0x7f8),&local_res10,&local_res8);

  if (cVar1 != '\0') {

    return local_res8;

  }

  local_res8 = (undefined8 *)FUN_1401841f0(0x20);

  local_24 = *(undefined4 *)(param_1 + 0x7c0);

  local_38[0] = 0x27;

  local_30 = 0;

  local_28 = 2;

  iVar2 = (**(code **)(param_1 + 0xaf8))(*(undefined8 *)(param_1 + 0x570),local_38,0,local_res8 + 1)

  ;

  if (iVar2 != 0) {

    FUN_1401841e0(local_res8);

    if (*(char *)(param_1 + 0x57c) != '\0') {

      uVar3 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"%s %s","vkCreateCommandPool",uVar3);

    }

    uVar3 = FUN_1401c0ba0(iVar2);

    FUN_14012e850("%s %s","vkCreateCommandPool",uVar3);

    return (undefined8 *)0x0;

  }

  *local_res8 = param_2;

  *(undefined4 *)(local_res8 + 3) = 0;

  *(undefined4 *)((longlong)local_res8 + 0x1c) = 0;

  local_res8[2] = 0;

  cVar1 = FUN_1401b2ca0(param_1,local_res8);

  if (cVar1 == '\0') {

    FUN_1401b8fa0(param_1,local_res8);

    return (undefined8 *)0x0;

  }

  puVar4 = (undefined8 *)FUN_1401841f0(8);

  *puVar4 = param_2;

  FUN_1401ab100(*(undefined8 *)(param_1 + 0x7f8),puVar4,local_res8,1);

  return local_res8;

}




