// Address: 0x14026e280
// Ghidra name: FUN_14026e280
// ============ 0x14026e280 FUN_14026e280 (size=364) ============


ulonglong FUN_14026e280(undefined8 *param_1)



{

  int iVar1;

  undefined8 *puVar2;

  ulonglong uVar3;

  undefined1 uVar4;

  undefined4 local_res8;

  undefined1 local_resc;

  undefined1 local_48 [64];

  

  uVar4 = 0;

  if ((*(short *)(param_1 + 4) == 0x54c) &&

     (iVar1 = FUN_14012f260(*param_1,"ShanWan",7), iVar1 == 0)) {

    uVar4 = 1;

  }

  if ((*(short *)(param_1 + 4) == 0x2563) || (*(short *)(param_1 + 4) == 0x20bc)) {

    uVar4 = 1;

  }

  puVar2 = (undefined8 *)FUN_1401841a0(1,0x60);

  uVar3 = 0;

  if (puVar2 == (undefined8 *)0x0) {

LAB_14026e366:

    uVar3 = uVar3 & 0xffffffffffffff00;

  }

  else {

    *puVar2 = param_1;

    *(undefined1 *)(puVar2 + 2) = uVar4;

    *(undefined1 *)((longlong)puVar2 + 0x11) = 1;

    param_1[0xe] = puVar2;

    if (*(char *)((longlong)param_1 + 0x54) == '\0') {

LAB_14026e338:

      iVar1 = FUN_14026ffd0(param_1[0x10],0xf2,local_48,0x11);

      if (iVar1 < 0) {

        uVar3 = FUN_14012e080(7,"HIDAPI_DriverPS3_InitDevice(): Couldn\'t read feature report 0xf2")

        ;

        goto LAB_14026e366;

      }

      iVar1 = FUN_14026ffd0(param_1[0x10],0xf5,local_48,8);

      if (iVar1 < 0) {

        uVar3 = FUN_14012e080(7,"HIDAPI_DriverPS3_InitDevice(): Couldn\'t read feature report 0xf5")

        ;

        return uVar3 & 0xffffffffffffff00;

      }

      if (*(char *)(puVar2 + 2) == '\0') {

        FUN_140195730(param_1[0x10],local_48,1);

      }

    }

    else {

      local_res8 = 0x342f4;

      local_resc = 0;

      thunk_FUN_140193880(param_1[0x10],&local_res8,5);

      if (*(char *)((longlong)param_1 + 0x54) == '\0') goto LAB_14026e338;

    }

    *(undefined4 *)((longlong)param_1 + 0x5c) = 4;

    FUN_1402083c0(param_1,"PS3 Controller");

    uVar3 = FUN_140208110(param_1,0);

  }

  return uVar3;

}




