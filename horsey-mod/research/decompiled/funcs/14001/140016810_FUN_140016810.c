// Address: 0x140016810
// Ghidra name: FUN_140016810
// ============ 0x140016810 FUN_140016810 (size=196) ============


ulonglong FUN_140016810(longlong param_1)



{

  int iVar1;

  uint _Line;

  float fVar2;

  ulonglong uVar3;

  float fVar4;

  

  iVar1 = *(int *)(param_1 + 0x6c);

  if (iVar1 == 0) {

    _Line = 0xf6;

  }

  else {

    if (iVar1 == 1) {

      return 0;

    }

    if (iVar1 == 2) {

      fVar2 = *(float *)(param_1 + 0x10) - *(float *)(param_1 + 0x34);

      fVar4 = *(float *)(param_1 + 0x14) - *(float *)(param_1 + 0x38);

      fVar2 = fVar4 * fVar4 + fVar2 * fVar2;

      if (fVar2 < 0.0) {

        uVar3 = FUN_1402cdfa0(fVar2);

        return uVar3;

      }

      return (ulonglong)(uint)SQRT(fVar2);

    }

    if (iVar1 == 3) {

      return (ulonglong)

             (uint)((*(float *)(param_1 + 0x5c) - *(float *)(param_1 + 0x14)) *

                    (*(float *)(param_1 + 0x34) - *(float *)(param_1 + 0x10)) -

                   (*(float *)(param_1 + 0x38) - *(float *)(param_1 + 0x14)) *

                   (*(float *)(param_1 + 0x58) - *(float *)(param_1 + 0x10)));

    }

    _Line = 0x103;

  }

  FID_conflict__assert(L"false",L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2Distance.cpp",_Line);

  return 0;

}




