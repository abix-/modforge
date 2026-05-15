// Address: 0x140024c00
// Ghidra name: FUN_140024c00
// ============ 0x140024c00 FUN_140024c00 (size=175) ============


undefined8 * FUN_140024c00(undefined8 *param_1,ulonglong param_2)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  

  *param_1 = TiXmlDeclaration::vftable;

  FUN_140027900(param_1 + 0x15);

  FUN_140027900(param_1 + 0x11);

  FUN_140027900(param_1 + 0xd);

  *param_1 = TiXmlNode::vftable;

  puVar2 = (undefined8 *)param_1[5];

  while (puVar2 != (undefined8 *)0x0) {

    puVar1 = (undefined8 *)puVar2[0xc];

    (**(code **)*puVar2)(puVar2,1);

    puVar2 = puVar1;

  }

  FUN_140027900(param_1 + 7);

  *param_1 = TiXmlBase::vftable;

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,200);

  }

  return param_1;

}




