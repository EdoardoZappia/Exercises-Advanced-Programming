from datasource import FileDataSource, ConsoleDataSource, LinearScaler, LogTransformer, StandardScaler


def main():
    input_type = input("Select input format (File | Console): ")
    if input_type == "File":
        filename = "../data.txt"
        data = FileDataSource(filename)
    elif input_type == "Console":
        data = ConsoleDataSource()
    else:
        print("Error: Invalid source type.")
        return 1

    print(data)
    data.read_data()

    print("\nOriginal data:\n")
    print(data)

    transformation_type = input("Select transformation to apply (Linear | Log | Standard): ")
    if transformation_type == "Linear":
        transformer = LinearScaler(data, 0.5)
    elif transformation_type == "Log":
        transformer = LogTransformer(data)
    elif transformation_type == "Standard":
        transformer = StandardScaler(data)
    else:
        print("Error: Invalid transformation type.")
        return 1

    transformer.transform()
    print("\nTransformed data:\n")
    print(data)

    return 0

main()
