// UFields(typedef vector<Fields> vectorField1d;)
Fields FieldsOperations;
Fields::vectorField1d U(mesh_.NumberOfNode); 
Fields::vectorField1d Unew(mesh_.NumberOfNode);

U = FieldsOperations.passGridinfomation(U, mesh_.xpts);
Unew = FieldsOperations.passGridinfomation(Unew, mesh_.xpts);