// Address: 0x140104600
// Ghidra name: FUN_140104600
// ============ 0x140104600 FUN_140104600 (size=172) ============


ulonglong FUN_140104600(longlong param_1,undefined8 *param_2)



{

  size_t sVar1;

  longlong lVar2;

  longlong lVar3;

  size_t _Size;

  int iVar4;

  void *_Buf1;

  undefined8 *_Buf2;

  ulonglong uVar5;

  ulonglong uVar6;

  

  sVar1 = param_2[2];

  if (sVar1 != 0) {

    lVar2 = *(longlong *)(param_1 + 0x438);

    uVar5 = 0;

    uVar6 = uVar5;

    do {

      lVar3 = *(longlong *)(lVar2 + uVar5 * 8);

      if (lVar3 != 0) {

        _Buf2 = param_2;

        if (0xf < (ulonglong)param_2[3]) {

          _Buf2 = (undefined8 *)*param_2;

        }

        _Buf1 = (void *)(lVar3 + 0x38);

        if (0xf < *(ulonglong *)(lVar3 + 0x50)) {

          _Buf1 = *(void **)(lVar3 + 0x38);

        }

        _Size = *(size_t *)(lVar3 + 0x48);

        if ((_Size == sVar1) && ((_Size == 0 || (iVar4 = memcmp(_Buf1,_Buf2,_Size), iVar4 == 0)))) {

          FUN_140027900(param_2);

          return uVar6;

        }

      }

      uVar6 = (ulonglong)((int)uVar6 + 1);

      uVar5 = uVar5 + 1;

    } while ((longlong)uVar5 < 0x30);

  }

  FUN_140027900(param_2);

  return 0xffffffff;

}




