// Address: 0x140215f20
// Ghidra name: FUN_140215f20
// ============ 0x140215f20 FUN_140215f20 (size=300) ============


undefined8 FUN_140215f20(longlong param_1,undefined4 param_2,undefined8 param_3)



{

  undefined8 *puVar1;

  longlong *plVar2;

  int iVar3;

  undefined8 uVar4;

  undefined4 local_res8 [2];

  undefined4 local_res10 [2];

  undefined8 local_res18;

  undefined8 local_res20;

  undefined4 *puVar5;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined4 local_3c;

  undefined8 local_38;

  undefined8 local_30;

  undefined8 uStack_28;

  undefined4 uVar6;

  

  plVar2 = (longlong *)**(undefined8 **)(param_1 + 200);

  puVar1 = *(undefined8 **)(param_1 + 200) + 1;

  local_3c = 0;

  local_30 = 0;

  uStack_28 = 0;

  local_48 = 0x28;

  local_44 = 0x18000;

  local_40 = param_2;

  local_38 = param_3;

  iVar3 = (**(code **)(*plVar2 + 0x18))(plVar2,&local_48,puVar1,0);

  if (iVar3 != 0) {

    uVar4 = FUN_140216c30("DirectSound CreateSoundBuffer",iVar3);

    return uVar4;

  }

  (**(code **)(*(longlong *)*puVar1 + 0x70))((longlong *)*puVar1,param_3);

  puVar5 = local_res10;

  iVar3 = (**(code **)(*(longlong *)*puVar1 + 0x58))

                    ((longlong *)*puVar1,0,local_40,&local_res18,puVar5,&local_res20,local_res8,2);

  uVar6 = (undefined4)((ulonglong)puVar5 >> 0x20);

  if (iVar3 == 0) {

    FUN_1402f94c0(local_res18,*(undefined4 *)(param_1 + 0x88),local_res10[0]);

    (**(code **)(*(longlong *)*puVar1 + 0x98))

              ((longlong *)*puVar1,local_res18,local_res10[0],local_res20,

               CONCAT44(uVar6,local_res8[0]));

  }

  return 1;

}




