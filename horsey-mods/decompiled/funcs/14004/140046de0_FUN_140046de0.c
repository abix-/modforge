// Address: 0x140046de0
// Ghidra name: FUN_140046de0
// ============ 0x140046de0 FUN_140046de0 (size=112) ============


uint FUN_140046de0(undefined8 *param_1,undefined8 *param_2)



{

  ulonglong uVar1;

  ulonglong uVar2;

  uint uVar3;

  undefined8 *_Buf1;

  ulonglong _Size;

  undefined8 *_Buf2;

  

  _Buf2 = param_2;

  if (0xf < (ulonglong)param_2[3]) {

    _Buf2 = (undefined8 *)*param_2;

  }

  _Buf1 = param_1;

  if (0xf < (ulonglong)param_1[3]) {

    _Buf1 = (undefined8 *)*param_1;

  }

  uVar1 = param_2[2];

  uVar2 = param_1[2];

  _Size = uVar2;

  if (uVar1 < uVar2) {

    _Size = uVar1;

  }

  uVar3 = memcmp(_Buf1,_Buf2,_Size);

  if (uVar3 == 0) {

    if (uVar2 < uVar1) {

      return 1;

    }

    uVar3 = 0;

  }

  return uVar3 >> 0x1f;

}




