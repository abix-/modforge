// Address: 0x1402168a0
// Ghidra name: FUN_1402168a0
// ============ 0x1402168a0 FUN_1402168a0 (size=186) ============


undefined4 FUN_1402168a0(longlong param_1,undefined8 param_2,undefined8 param_3)



{

  longlong lVar1;

  int iVar2;

  undefined4 local_res8 [2];

  undefined4 local_res18 [2];

  undefined8 local_res20;

  undefined4 *puVar3;

  undefined8 local_18 [2];

  undefined4 uVar4;

  

  lVar1 = *(longlong *)(param_1 + 200);

  puVar3 = local_res18;

  iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x18) + 0x40))

                    (*(longlong **)(lVar1 + 0x18),(int)param_3 * *(int *)(lVar1 + 0x24),param_3,

                     &local_res20,puVar3,local_18,local_res8,0);

  uVar4 = (undefined4)((ulonglong)puVar3 >> 0x20);

  if (iVar2 == 0) {

    FUN_1402f8e20(param_2,local_res20,local_res18[0]);

    iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x18) + 0x58))

                      (*(longlong **)(lVar1 + 0x18),local_res20,local_res18[0],local_18[0],

                       CONCAT44(uVar4,local_res8[0]));

    if (iVar2 == 0) {

      *(uint *)(lVar1 + 0x24) = (*(int *)(lVar1 + 0x24) + 1U) % *(uint *)(lVar1 + 0x20);

      return local_res18[0];

    }

  }

  return 0xffffffff;

}




