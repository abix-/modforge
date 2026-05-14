// Address: 0x1400273e0
// Ghidra name: FUN_1400273e0
// ============ 0x1400273e0 FUN_1400273e0 (size=141) ============


longlong FUN_1400273e0(longlong param_1,undefined8 *param_2)



{

  ulonglong uVar1;

  size_t sVar2;

  size_t _Size;

  int iVar3;

  undefined8 *_Buf1;

  undefined8 *_Buf2;

  longlong lVar4;

  

  lVar4 = *(longlong *)(param_1 + 0x68);

  if (lVar4 != param_1) {

    uVar1 = param_2[3];

    sVar2 = param_2[2];

    do {

      _Buf1 = (undefined8 *)(lVar4 + 0x20);

      _Buf2 = param_2;

      if (0xf < uVar1) {

        _Buf2 = (undefined8 *)*param_2;

      }

      if (0xf < *(ulonglong *)(lVar4 + 0x38)) {

        _Buf1 = (undefined8 *)*_Buf1;

      }

      _Size = *(size_t *)(lVar4 + 0x30);

      if (_Size == sVar2) {

        if (_Size == 0) {

          return lVar4;

        }

        iVar3 = memcmp(_Buf1,_Buf2,_Size);

        if (iVar3 == 0) {

          return lVar4;

        }

      }

      lVar4 = *(longlong *)(lVar4 + 0x68);

    } while (lVar4 != param_1);

  }

  return 0;

}




