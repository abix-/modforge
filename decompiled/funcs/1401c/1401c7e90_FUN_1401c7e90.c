// Address: 0x1401c7e90
// Ghidra name: FUN_1401c7e90
// ============ 0x1401c7e90 FUN_1401c7e90 (size=267) ============


undefined8 * FUN_1401c7e90(longlong param_1,undefined4 param_2,undefined4 param_3,char param_4)



{

  int iVar1;

  undefined4 uVar2;

  undefined8 *puVar3;

  longlong *local_28;

  undefined4 local_20;

  undefined4 local_1c;

  uint local_18;

  undefined4 local_14;

  

  puVar3 = (undefined8 *)FUN_1401841a0(1,0x30);

  if (puVar3 != (undefined8 *)0x0) {

    *(undefined4 *)((longlong)puVar3 + 0x2c) = 0;

    local_14 = 0;

    local_18 = (uint)(param_4 == '\0');

    local_20 = param_2;

    local_1c = param_3;

    iVar1 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x70))

                      (*(longlong **)(param_1 + 0x70),&local_20,&DAT_1403492e8,&local_28);

    if (-1 < iVar1) {

      *puVar3 = local_28;

      *(undefined4 *)(puVar3 + 1) = param_2;

      *(undefined4 *)(puVar3 + 4) = param_3;

      *(char *)(puVar3 + 5) = param_4;

      uVar2 = (**(code **)(**(longlong **)(param_1 + 0x70) + 0x78))

                        (*(longlong **)(param_1 + 0x70),param_2);

      *(undefined4 *)((longlong)puVar3 + 0x24) = uVar2;

      (**(code **)(*local_28 + 0x48))(local_28,puVar3 + 2);

      if (param_4 != '\0') {

        return puVar3;

      }

      (**(code **)(*local_28 + 0x50))(local_28,puVar3 + 3);

      return puVar3;

    }

    FUN_1401cb240(param_1,"Failed to create descriptor heap!",iVar1);

    FUN_1401c9730(puVar3);

  }

  return (undefined8 *)0x0;

}




