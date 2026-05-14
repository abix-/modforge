// Address: 0x14001d240
// Ghidra name: FUN_14001d240
// ============ 0x14001d240 FUN_14001d240 (size=454) ============


undefined8 * FUN_14001d240(undefined8 *param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  undefined8 uVar3;

  longlong lVar4;

  float fVar5;

  float fVar6;

  

  FUN_140010c10();

  fVar2 = DAT_14039ca90;

  fVar1 = DAT_14039ca68;

  *param_1 = b2MouseJoint::vftable;

  if ((((*(float *)(param_2 + 0x28) <= fVar2) || (fVar1 <= *(float *)(param_2 + 0x28))) ||

      (*(float *)(param_2 + 0x2c) <= fVar2)) || (fVar1 <= *(float *)(param_2 + 0x2c))) {

    FID_conflict__assert

              (L"def->target.IsValid()",

               L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Joints\\b2MouseJoint.cpp",0x22);

  }

  fVar5 = *(float *)(param_2 + 0x30);

  if (((fVar5 <= fVar2) || (fVar1 <= fVar5)) || (fVar5 < 0.0)) {

    FID_conflict__assert

              (L"b2IsValid(def->maxForce) && def->maxForce >= 0.0f",

               L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Joints\\b2MouseJoint.cpp",0x23);

  }

  fVar5 = *(float *)(param_2 + 0x34);

  if (((fVar5 <= fVar2) || (fVar1 <= fVar5)) || (fVar5 < 0.0)) {

    FID_conflict__assert

              (L"b2IsValid(def->frequencyHz) && def->frequencyHz >= 0.0f",

               L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Joints\\b2MouseJoint.cpp",0x24);

  }

  fVar5 = *(float *)(param_2 + 0x38);

  if (((fVar5 <= fVar2) || (fVar1 <= fVar5)) || (fVar5 < 0.0)) {

    FID_conflict__assert

              (L"b2IsValid(def->dampingRatio) && def->dampingRatio >= 0.0f",

               L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Joints\\b2MouseJoint.cpp",0x25);

  }

  uVar3 = *(undefined8 *)(param_2 + 0x28);

  lVar4 = param_1[0xd];

  param_1[0x11] = uVar3;

  fVar6 = (float)uVar3 - *(float *)(lVar4 + 0xc);

  fVar1 = *(float *)(lVar4 + 0x18);

  fVar2 = *(float *)(lVar4 + 0x14);

  fVar5 = *(float *)((longlong)param_1 + 0x8c) - *(float *)(lVar4 + 0x10);

  *(float *)(param_1 + 0x10) = fVar2 * fVar5 + fVar1 * fVar6;

  *(float *)((longlong)param_1 + 0x84) = fVar1 * fVar5 - fVar2 * fVar6;

  *(undefined4 *)((longlong)param_1 + 0xa4) = *(undefined4 *)(param_2 + 0x30);

  *(undefined8 *)((longlong)param_1 + 0x9c) = 0;

  *(undefined4 *)(param_1 + 0x12) = *(undefined4 *)(param_2 + 0x34);

  *(undefined4 *)((longlong)param_1 + 0x94) = *(undefined4 *)(param_2 + 0x38);

  *(undefined4 *)(param_1 + 0x13) = 0;

  *(undefined4 *)(param_1 + 0x15) = 0;

  return param_1;

}




