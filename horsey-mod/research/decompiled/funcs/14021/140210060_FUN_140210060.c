// Address: 0x140210060
// Ghidra name: FUN_140210060
// ============ 0x140210060 FUN_140210060 (size=535) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140210060(undefined8 param_1,longlong *param_2,undefined8 param_3)



{

  float fVar1;

  char cVar2;

  byte bVar3;

  byte bVar4;

  ushort *puVar5;

  float fVar6;

  float fVar7;

  uint local_58;

  float local_54;

  float local_50;

  float local_4c;

  uint local_48;

  float local_44;

  uint local_40;

  

  cVar2 = (**(code **)(*param_2 + 0xb0))(param_2,&local_58);

  if (cVar2 != '\0') {

    bVar4 = 0;

    puVar5 = &DAT_1403e51c0;

    do {

      if (*puVar5 != 0) {

        FUN_14015ad00(param_3,param_1,bVar4,(local_58 & *puVar5) != 0);

      }

      bVar4 = bVar4 + 1;

      puVar5 = puVar5 + 1;

    } while (bVar4 < 0xb);

    bVar3 = (byte)(local_58 >> 6) & 1;

    bVar4 = bVar3 | 4;

    if ((local_58 & 0x80) == 0) {

      bVar4 = bVar3;

    }

    bVar3 = bVar4 | 8;

    if ((local_58 >> 8 & 1) == 0) {

      bVar3 = bVar4;

    }

    bVar4 = bVar3 | 2;

    if ((local_58 >> 9 & 1) == 0) {

      bVar4 = bVar3;

    }

    FUN_14015ae90(param_3,param_1,0,bVar4);

    fVar1 = _DAT_140350d1c;

    fVar7 = DAT_1403053f0;

    fVar6 = DAT_1403053f0;

    if (local_4c < 0.0) {

      fVar6 = _DAT_140350d1c;

    }

    FUN_14015aab0(param_3,param_1,0,(int)(local_4c * fVar6));

    fVar6 = fVar7;

    if ((float)(local_48 ^ DAT_14039cac0) < 0.0) {

      fVar6 = fVar1;

    }

    FUN_14015aab0(param_3,param_1,1,(int)((float)(local_48 ^ DAT_14039cac0) * fVar6));

    fVar6 = fVar7;

    if (local_44 < 0.0) {

      fVar6 = fVar1;

    }

    FUN_14015aab0(param_3,param_1,2,(int)(local_44 * fVar6));

    if ((float)(local_40 ^ DAT_14039cac0) < 0.0) {

      fVar7 = fVar1;

    }

    FUN_14015aab0(param_3,param_1,3,(int)((float)(local_40 ^ DAT_14039cac0) * fVar7));

    FUN_14015aab0(param_3,param_1,4,(int)(local_54 * DAT_14030ec38 - fVar1));

    FUN_14015aab0(param_3,param_1,5,(int)(local_50 * DAT_14030ec38 - fVar1));

  }

  return;

}




