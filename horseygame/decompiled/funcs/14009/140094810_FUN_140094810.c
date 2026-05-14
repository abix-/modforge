// Address: 0x140094810
// Ghidra name: FUN_140094810
// ============ 0x140094810 FUN_140094810 (size=467) ============


void FUN_140094810(longlong param_1,undefined8 param_2,undefined8 *param_3)



{

  float fVar1;

  float fVar2;

  undefined8 *puVar3;

  float fVar4;

  float fVar5;

  

  if (*(longlong *)(param_1 + 0x3a8) != 0) {

    FUN_1400b8720();

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x3a8),param_2,0 < *(int *)(param_1 + 0x1f8),

                  DAT_140304024);

    if ((undefined8 *)(param_1 + 0x3b0) != param_3) {

      puVar3 = param_3;

      if (0xf < (ulonglong)param_3[3]) {

        puVar3 = (undefined8 *)*param_3;

      }

      FUN_140027f50((undefined8 *)(param_1 + 0x3b0),puVar3,param_3[2]);

    }

    if ((*(longlong **)(param_1 + 0x130) == *(longlong **)(param_1 + 0x138)) ||

       (*(longlong *)(param_1 + 0x3a8) != **(longlong **)(param_1 + 0x130))) {

      *(undefined4 *)(param_1 + 0x1d0) = 0x42900000;

      fVar1 = *(float *)(param_1 + 0x114);

      fVar5 = ((float)DAT_1403d9e68 - DAT_140304028) / fVar1 + *(float *)(param_1 + 0x10c);

      *(float *)(param_1 + 0x1c8) = fVar5;

      fVar4 = DAT_140304014 / fVar1 + *(float *)(param_1 + 0x110);

      *(float *)(param_1 + 0x1cc) = fVar4;

      *(undefined4 *)(param_1 + 0x1d8) = DAT_1403da064;

      fVar2 = DAT_140303390;

      if ((*(longlong *)(param_1 + 0x1e8) - *(longlong *)(param_1 + 0x1e0) & 0xffffffffffffffe0U) ==

          0x60) {

        fVar4 = fVar4 - DAT_140303390 / fVar1;

        *(float *)(param_1 + 0x1cc) = fVar4;

      }

      FUN_1400c9c30(param_1,1,(int)((fVar5 - *(float *)(param_1 + 0x10c)) * DAT_140303fd0 - fVar2),

                    (int)((fVar4 - *(float *)(param_1 + 0x110)) * DAT_140303fd0 - fVar2),0x50,

                    (int)(*(float *)(param_1 + 0x1d4) + DAT_14039ca58),1);

      *(undefined4 *)(param_1 + 0x1f8) = 36000;

      *(undefined4 *)(param_1 + 0x200) = 0;

    }

  }

  FUN_140027900(param_2);

  FUN_140027900(param_3);

  return;

}




