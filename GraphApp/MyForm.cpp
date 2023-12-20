#include "Graph.h"
#include "MyForm.h"
#include <cmath>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <Map>
#include <queue>
#include <fstream>
#include <string>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    GraphApp::MyForm form;
    Application::Run(% form);
}