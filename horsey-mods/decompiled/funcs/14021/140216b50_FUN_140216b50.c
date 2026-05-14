// Address: 0x140216b50
// Ghidra name: FUN_140216b50
// ============ 0x140216b50 FUN_140216b50 (size=222) ============


undefined8

FUN_140216b50(undefined4 *param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  int iVar4;

  longlong lVar5;

  undefined4 *_Buf1;

  longlong lVar6;

  

  if (param_1 == (undefined4 *)0x0) {

    return 1;

  }

  lVar5 = FUN_1401a9b00(param_2,param_1);

  if (lVar5 != 0) {

    _Buf1 = (undefined4 *)FUN_1401841f0(0x10);

    if (_Buf1 != (undefined4 *)0x0) {

      uVar1 = param_1[1];

      uVar2 = param_1[2];

      uVar3 = param_1[3];

      *_Buf1 = *param_1;

      _Buf1[1] = uVar1;

      _Buf1[2] = uVar2;

      _Buf1[3] = uVar3;

      lVar6 = FUN_14015d410(*param_4,lVar5,0,_Buf1);

      if (((lVar6 != 0) && (*(longlong *)(param_4 + 8) != 0)) &&

         (*(void **)(param_4 + 0x10) != (void *)0x0)) {

        iVar4 = memcmp(_Buf1,*(void **)(param_4 + 0x10),0x10);

        if (iVar4 == 0) {

          **(longlong **)(param_4 + 8) = lVar6;

        }

      }

    }

    FUN_1401841e0(lVar5);

    return 1;

  }

  return 1;

}




