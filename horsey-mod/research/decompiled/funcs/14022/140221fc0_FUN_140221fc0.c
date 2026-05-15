// Address: 0x140221fc0
// Ghidra name: FUN_140221fc0
// ============ 0x140221fc0 FUN_140221fc0 (size=293) ============


undefined8 FUN_140221fc0(longlong param_1)



{

  undefined1 auVar1 [16];

  char cVar2;

  int iVar3;

  undefined8 *puVar4;

  longlong lVar5;

  ulonglong uVar6;

  longlong lVar7;

  

  if (*(longlong *)(*(longlong *)(param_1 + 0x680) + 0x138) != 0) {

    return CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x680) >> 8),1);

  }

  puVar4 = (undefined8 *)FUN_1401841a0(1,0x38);

  if (puVar4 != (undefined8 *)0x0) {

    *(undefined8 **)(*(longlong *)(param_1 + 0x680) + 0x138) = puVar4;

    lVar5 = FUN_140179a30();

    puVar4[5] = lVar5;

    if (lVar5 != 0) {

      cVar2 = FUN_140289250(puVar4);

      if (cVar2 != '\0') {

        iVar3 = (**(code **)(*(longlong *)*puVar4 + 0x48))

                          ((longlong *)*puVar4,0,0x30,1,2,puVar4,&LAB_140221d90,puVar4 + 1);

        if (-1 < iVar3) {

          uVar6 = FUN_140149300();

          lVar5 = (**(code **)(*(longlong *)*puVar4 + 0x18))();

          auVar1._8_8_ = 0;

          auVar1._0_8_ = uVar6;

          lVar7 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar1,8);

          puVar4[6] = ((uVar6 - lVar7 >> 1) + lVar7 >> 9) - lVar5;

          return 1;

        }

        FUN_1401a9ef0("IGameInput::RegisterDeviceCallback",iVar3);

      }

    }

  }

  FUN_1402220f0(param_1);

  return 0;

}




