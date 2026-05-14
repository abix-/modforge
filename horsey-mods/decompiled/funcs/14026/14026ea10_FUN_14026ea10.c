// Address: 0x14026ea10
// Ghidra name: FUN_14026ea10
// ============ 0x14026ea10 FUN_14026ea10 (size=201) ============


uint FUN_14026ea10(longlong param_1)



{

  int iVar1;

  uint uVar2;

  longlong *plVar3;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  plVar3 = (longlong *)FUN_1401841a0(1,0x60);

  uVar2 = (uint)plVar3;

  if (plVar3 == (longlong *)0x0) {

LAB_14026eaab:

    return uVar2 & 0xffffff00;

  }

  *plVar3 = param_1;

  *(undefined1 *)((longlong)plVar3 + 0x11) = 1;

  *(longlong **)(param_1 + 0x70) = plVar3;

  iVar1 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),0xf2,&local_48,0x40);

  if (iVar1 < 0) {

    FUN_14012e080(7,

                  "HIDAPI_DriverPS3SonySixaxis_InitDevice(): Couldn\'t read feature report 0xf2. Trying again with 0x0."

                 );

    local_48 = 0;

    uStack_40 = 0;

    local_38 = 0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    iVar1 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),0,&local_48,0x40);

    if (iVar1 < 0) {

      uVar2 = FUN_14012e080(7,

                            "HIDAPI_DriverPS3SonySixaxis_InitDevice(): Couldn\'t read feature report 0x00."

                           );

      goto LAB_14026eaab;

    }

  }

  *(undefined4 *)(param_1 + 0x5c) = 4;

  FUN_1402083c0(param_1,"PS3 Controller");

  uVar2 = FUN_140208110(param_1,0);

  return uVar2;

}




