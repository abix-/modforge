// Address: 0x14013fc10
// Ghidra name: FUN_14013fc10
// ============ 0x14013fc10 FUN_14013fc10 (size=722) ============


undefined4 * FUN_14013fc10(undefined4 *param_1,undefined8 param_2,undefined1 *param_3,int param_4)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  undefined4 *puVar7;

  int iVar8;

  longlong lVar9;

  char *_Str;

  undefined1 *puVar10;

  longlong lVar11;

  size_t sVar12;

  undefined4 *puVar13;

  undefined1 *puVar14;

  undefined *puVar15;

  ushort local_58 [8];

  undefined4 local_48;

  undefined4 uStack_44;

  undefined4 uStack_40;

  undefined4 uStack_3c;

  undefined4 local_38;

  undefined4 uStack_34;

  undefined4 uStack_30;

  undefined4 uStack_2c;

  

  _guard_check_icall();

  lVar9 = FUN_140140a30(param_2);

  if (lVar9 == 0) {

    FUN_14012e850("Couldn\'t parse name from %s",param_2);

    return (undefined4 *)0x0;

  }

  _Str = (char *)FUN_140140990(param_2);

  if (_Str == (char *)0x0) {

    FUN_1401841e0(lVar9);

    FUN_14012e850("Couldn\'t parse %s",param_2);

    puVar13 = (undefined4 *)0x0;

  }

  else {

    local_48 = *param_1;

    uStack_44 = param_1[1];

    uStack_40 = param_1[2];

    uStack_3c = param_1[3];

    FUN_1401582b0(&local_48,0,0,0,local_58);

    if (local_58[0] == 0) {

      lVar11 = thunk_FUN_1402c9340(_Str,&DAT_1403318d4);

      if ((lVar11 != 0) && (local_58[0] = thunk_FUN_1402d8a8c(lVar11 + 4,0,0x10), local_58[0] != 0))

      {

        FUN_14015b420(param_1,local_58[0]);

      }

    }

    else {

      puVar15 = &DAT_14039bcb9;

      puVar14 = &DAT_14039bcb9;

      puVar10 = (undefined1 *)thunk_FUN_1402c9340(_Str,&DAT_1403318d4);

      if (puVar10 != (undefined1 *)0x0) {

        lVar11 = thunk_FUN_1402c9190(puVar10,0x2c);

        if (lVar11 == 0) {

          puVar14 = &DAT_14039bcb9;

        }

        else {

          puVar14 = (undefined1 *)(lVar11 + 1);

        }

        *puVar10 = 0;

      }

      sVar12 = strlen(_Str);

      if ((sVar12 != 0) && (_Str[sVar12 - 1] != ',')) {

        puVar15 = &DAT_140331a5c;

      }

      iVar8 = FUN_14012ee40(&local_48,"%s%s%s%.4x,%s",_Str,puVar15,&DAT_1403318d4,local_58[0],

                            puVar14);

      if (-1 < iVar8) {

        FUN_1401841e0(_Str);

        _Str = (char *)CONCAT44(uStack_44,local_48);

      }

    }

    FUN_14013c7b0();

    local_38 = *param_1;

    uStack_34 = param_1[1];

    uStack_30 = param_1[2];

    uStack_2c = param_1[3];

    puVar13 = (undefined4 *)FUN_1401407d0(&local_38,1);

    if (puVar13 == (undefined4 *)0x0) {

      puVar13 = (undefined4 *)FUN_1401841f0(0x30);

      if (puVar13 == (undefined4 *)0x0) {

        FUN_14013c640();

        FUN_1401841e0(lVar9);

        FUN_1401841e0(_Str);

        return (undefined4 *)0x0;

      }

      if (local_58[0] != 0) {

        FUN_14015b420(param_1,0);

      }

      puVar6 = DAT_1403fbf18;

      uVar1 = *param_1;

      uVar2 = param_1[1];

      uVar3 = param_1[2];

      uVar4 = param_1[3];

      *(longlong *)(puVar13 + 4) = lVar9;

      *(char **)(puVar13 + 6) = _Str;

      *(undefined8 *)(puVar13 + 10) = 0;

      puVar13[8] = param_4;

      *puVar13 = uVar1;

      puVar13[1] = uVar2;

      puVar13[2] = uVar3;

      puVar13[3] = uVar4;

      puVar7 = puVar13;

      if (puVar6 != (undefined4 *)0x0) {

        puVar7 = *(undefined4 **)(puVar6 + 10);

        while (puVar5 = puVar7, puVar5 != (undefined4 *)0x0) {

          puVar6 = puVar5;

          puVar7 = *(undefined4 **)(puVar5 + 10);

        }

        *(undefined4 **)(puVar6 + 10) = puVar13;

        puVar7 = DAT_1403fbf18;

      }

      DAT_1403fbf18 = puVar7;

      if (param_3 != (undefined1 *)0x0) {

        *param_3 = 0;

      }

    }

    else {

      if (param_4 < (int)puVar13[8]) {

        FUN_1401841e0(lVar9);

        FUN_1401841e0(_Str);

      }

      else {

        FUN_1401841e0(*(undefined8 *)(puVar13 + 4));

        *(longlong *)(puVar13 + 4) = lVar9;

        FUN_1401841e0(*(undefined8 *)(puVar13 + 6));

        *(char **)(puVar13 + 6) = _Str;

        puVar13[8] = param_4;

      }

      if (param_3 != (undefined1 *)0x0) {

        *param_3 = 1;

      }

      FUN_14013bfc0(puVar13);

    }

    FUN_14013c640();

  }

  return puVar13;

}




