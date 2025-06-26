class string {
    static {
        System.out.println("Static block");
        System.exit(0);
    }
    public static void main(String[] args) {
        System.out.println("Main method");
    }
}