#include "ShapeCommandRealization.h"

void ShapeCommandRealization::ProcessShapes()
{
    std::vector<std::unique_ptr<IShape>> shapes;
    std::string commandLine;

    std::cout << PROMPT_MESSAGE << std::endl;

    while (std::getline(std::cin, commandLine))
    {
        if (commandLine.empty()) continue;
        ProcessCommand(shapes, commandLine);
    }

    PrintResults(shapes);
}

void ShapeCommandRealization::ProcessCommand(std::vector<std::unique_ptr<IShape>>& shapes, const std::string& commandLine)
{
    ParsedCommand cmd = ParseCommand(commandLine);

    switch (cmd.type)
    {
    case CommandType::LINE_SEGMENT:
        RealizeLineSegment(shapes, cmd.arguments);
        break;

    case CommandType::TRIANGLE:
        RealizeTriangle(shapes, cmd.arguments);
        break;

    case CommandType::RECTANGLE:
        RealizeRectangle(shapes, cmd.arguments);
        break;

    case CommandType::CIRCLE:
        RealizeCircle(shapes, cmd.arguments);
        break;

    case CommandType::UNKNOWN:
    default:
        std::cout << UNKNOWN_COMMAND << std::endl;
        break;
    }
}

ParsedCommand ShapeCommandRealization::ParseCommand(const std::string& input)
{
    std::istringstream iss(input);
    std::string action;
    iss >> action;

    if (action.empty())
    {
        return { CommandType::UNKNOWN, {} };
    }

    std::string actionLower = action;
    std::transform(actionLower.begin(), actionLower.end(), actionLower.begin(), ::tolower);

    auto it = COMMAND_MAP.find(actionLower);
    if (it != COMMAND_MAP.end())
    {
        ParsedCommand result;
        result.type = it->second;

        std::string arg;
        while (iss >> arg)
        {
            result.arguments.push_back(arg);
        }

        return result;
    }

    return { CommandType::UNKNOWN, {} };
}

uint32_t ShapeCommandRealization::GetColor(const std::string& colorStr)
{
    if (colorStr.length() >= 1 && colorStr[0] == HASH_CHAR)
    {
        std::string hexStr = colorStr.substr(1);
        try
        {
            return static_cast<uint32_t>(std::stoul(hexStr, nullptr, HEX_BASE));
        }
        catch (...)
        {
            return 0;
        }
    }
    else
    {
        try
        {
            return static_cast<uint32_t>(std::stoul(colorStr, nullptr, HEX_BASE));
        }
        catch (...)
        {
            return 0;
        }
    }
}

const IShape* ShapeCommandRealization::GetShapeWithMaxArea(const std::vector<std::unique_ptr<IShape>>& shapes)
{
    if (shapes.empty()) return nullptr;

    auto maxAreaShape = std::max_element(shapes.begin(), shapes.end(),
        [](const std::unique_ptr<IShape>& first, const std::unique_ptr<IShape>& second)
        {
            return first->GetArea() < second->GetArea();
        });

    return maxAreaShape->get();
}

const IShape* ShapeCommandRealization::GetShapeWithMinPerimeter(const std::vector<std::unique_ptr<IShape>>& shapes)
{
    if (shapes.empty()) return nullptr;

    auto minPerimeterShape = std::min_element(shapes.begin(), shapes.end(),
        [](const std::unique_ptr<IShape>& first, const std::unique_ptr<IShape>& second)
        {
            return first->GetPerimeter() < second->GetPerimeter();
        });

    return minPerimeterShape->get();
}

void ShapeCommandRealization::RealizeLineSegment(std::vector<std::unique_ptr<IShape>>& shapes, const std::vector<std::string>& args)
{
    if (args.size() != LINE_SEGMENT_ARGS_COUNT)
    {
        std::cout << INVALID_ARGUMENT_COUNT_LINE_SEGMENT << args.size() << std::endl;
        return;
    }

    try
    {
        double startX = std::stod(args[LINE_SEGMENT_ARGS_COUNT - 5]);
        double startY = std::stod(args[LINE_SEGMENT_ARGS_COUNT - 4]);
        double endX = std::stod(args[LINE_SEGMENT_ARGS_COUNT - 3]);
        double endY = std::stod(args[LINE_SEGMENT_ARGS_COUNT - 2]);
        uint32_t outlineColor = GetColor(args[LINE_SEGMENT_ARGS_COUNT - 1]);

        shapes.push_back(std::make_unique<CLineSegment>(
            startX,
            startY,
            endX,
            endY,
            outlineColor
        ));
    }
    catch (const std::exception&)
    {
        std::cout << INVALID_COORDINATES << std::endl;
    }
}

void ShapeCommandRealization::RealizeTriangle(std::vector<std::unique_ptr<IShape>>& shapes, const std::vector<std::string>& args)
{
    if (args.size() != TRIANGLE_ARGS_COUNT)
    {
        std::cout << INVALID_ARGUMENT_COUNT_TRIANGLE << args.size() << std::endl;
        return;
    }

    try
    {
        double x1 = std::stod(args[TRIANGLE_ARGS_COUNT - 8]);
        double y1 = std::stod(args[TRIANGLE_ARGS_COUNT - 7]);
        double x2 = std::stod(args[TRIANGLE_ARGS_COUNT - 6]);
        double y2 = std::stod(args[TRIANGLE_ARGS_COUNT - 5]);
        double x3 = std::stod(args[TRIANGLE_ARGS_COUNT - 4]);
        double y3 = std::stod(args[TRIANGLE_ARGS_COUNT - 3]);
        uint32_t outlineColor = GetColor(args[TRIANGLE_ARGS_COUNT - 2]);
        uint32_t fillColor = GetColor(args[TRIANGLE_ARGS_COUNT - 1]);

        shapes.push_back(std::make_unique<CTriangle>(
            x1, y1, x2, y2, x3, y3,
            outlineColor,
            fillColor
        ));
    }
    catch (const std::exception&)
    {
        std::cout << INVALID_COORDINATES << std::endl;
    }
}

void ShapeCommandRealization::RealizeRectangle(std::vector<std::unique_ptr<IShape>>& shapes, const std::vector<std::string>& args)
{
    if (args.size() != RECTANGLE_ARGS_COUNT)
    {
        std::cout << INVALID_ARGUMENT_COUNT_RECTANGLE << args.size() << std::endl;
        return;
    }

    try
    {
        double x1 = std::stod(args[RECTANGLE_ARGS_COUNT - 6]);
        double y1 = std::stod(args[RECTANGLE_ARGS_COUNT - 5]);
        double x2 = std::stod(args[RECTANGLE_ARGS_COUNT - 4]);
        double y2 = std::stod(args[RECTANGLE_ARGS_COUNT - 3]);
        uint32_t outlineColor = GetColor(args[RECTANGLE_ARGS_COUNT - 2]);
        uint32_t fillColor = GetColor(args[RECTANGLE_ARGS_COUNT - 1]);

        shapes.push_back(std::make_unique<CRectangle>(
            x1, y1, x2, y2,
            outlineColor,
            fillColor
        ));
    }
    catch (const std::exception&)
    {
        std::cout << INVALID_DIMENSIONS << std::endl;
    }
}

void ShapeCommandRealization::RealizeCircle(std::vector<std::unique_ptr<IShape>>& shapes, const std::vector<std::string>& args)
{
    if (args.size() != CIRCLE_ARGS_COUNT)
    {
        std::cout << INVALID_ARGUMENT_COUNT_CIRCLE << args.size() << std::endl;
        return;
    }

    try
    {
        double x = std::stod(args[CIRCLE_ARGS_COUNT - 5]);
        double y = std::stod(args[CIRCLE_ARGS_COUNT - 4]);
        double radius = std::stod(args[CIRCLE_ARGS_COUNT - 3]);
        uint32_t outlineColor = GetColor(args[CIRCLE_ARGS_COUNT - 2]);
        uint32_t fillColor = GetColor(args[CIRCLE_ARGS_COUNT - 1]);

        shapes.push_back(std::make_unique<CCircle>(
            x, y, radius,
            outlineColor,
            fillColor
        ));
    }
    catch (const std::exception&)
    {
        std::cout << INVALID_COORDINATES_AND_RADIUS << std::endl;
    }
}

void ShapeCommandRealization::PrintResults(const std::vector<std::unique_ptr<IShape>>& shapes)
{
    if (shapes.empty())
    {
        std::cout << NO_SHAPES_MESSAGE << std::endl;
        return;
    }

    std::cout << ALL_SHAPES_HEADER << std::endl;
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        std::cout << (i + 1) << SHAPE_INDEX_SEPARATOR << shapes[i]->ToString() << std::endl;
    }

    const IShape* maxAreaShape = GetShapeWithMaxArea(shapes);
    const IShape* minPerimeterShape = GetShapeWithMinPerimeter(shapes);

    std::cout << MAX_AREA_HEADER << std::endl;
    if (maxAreaShape)
    {
        PrintShapeDetails(maxAreaShape);
    }

    std::cout << MIN_PERIMETER_HEADER << std::endl;
    if (minPerimeterShape)
    {
        PrintShapeDetails(minPerimeterShape);
    }
}

void ShapeCommandRealization::PrintShapeDetails(const IShape* shape)
{
    std::cout << shape->ToString() << std::endl;
    std::cout << AREA_LABEL << std::fixed << std::setprecision(DOUBLE_PRECISION) << shape->GetArea() << std::endl;
    std::cout << PERIMETER_LABEL << std::fixed << std::setprecision(DOUBLE_PRECISION) << shape->GetPerimeter() << std::endl;
    std::cout << OUTLINE_COLOR_LABEL << std::hex << std::setfill(ZERO_CHAR) << std::setw(COLOR_WIDTH) << shape->GetOutlineColor() << std::dec << std::endl;

    const ISolidShape* solidShape = dynamic_cast<const ISolidShape*>(shape);
    if (solidShape)
    {
        std::cout << FILL_COLOR_LABEL << std::hex << std::setfill(ZERO_CHAR) << std::setw(COLOR_WIDTH) << solidShape->GetFillColor() << std::dec << std::endl;
    }
}